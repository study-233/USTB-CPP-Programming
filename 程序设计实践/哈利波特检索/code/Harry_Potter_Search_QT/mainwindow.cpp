#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <string>

using namespace std;

// Text 类，用于存储每个文本条目信息
class Text
{
public:
    int page;       // 页码
    string chapter; // 章节
    string book;    // 书
    string content; // 内容
};

// 函数声明
void readBooks(const vector<string>& filenames);
void searchNameInBooks(string info, vector<int> & s);
void displayResults(vector<int> s, string info);

// 全局变量
vector<Text> text; // 用于存储所有文本条目
Text TempContent; // 临时 Text 对象，用于读取文件内容
vector<int> search_Info; // 用于存储搜索结果

MainWindow *MainWindow::my = nullptr; // 指向 MainWindow 实例的指针

// 哈利波特系列书籍文件名
vector<string> filenames = {
    "HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_",
    "HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_",
    "J.K. Rowling - HP 0 - Harry Potter Prequel",
    "J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban",
    "J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire",
    "J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince",
    "J.K. Rowling - Quidditch Through the Ages",
    "J.K. Rowling - The Tales of Beedle the Bard"
};

// 构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my = this; // 将当前 MainWindow 实例指针赋值给 my
    // 读取文本文件内容
    readBooks(filenames);
    // ui->tableWidget->setColumnWidth(0,20);
    // ui->tableWidget->setColumnWidth(1,20);
    // ui->tableWidget->setColumnWidth(2,20);
    // ui->tableWidget->setColumnWidth(3,20);
    // ui->tableWidget->setColumnWidth(4,20);
    ui->tableWidget->setColumnCount(5); // 设置表格列数为5
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "序号"<<"人名/地名"<<"页码"<<"章节"<<"书名"); // 设置表格头
    // 设置列内容自适应宽度
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

// 析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

// 读取文件，将内容存储到 text 向量中
void readBooks(const vector<string>& filenames) {

    for (string filename : filenames) {
        TempContent.book = filename; // 假设文件名即为书名
        TempContent.page = 1;
        TempContent.chapter = "Chapter Zero";

        ifstream file; // 创建文件输入流对象
        file.open(filename+".txt"); // 打开文件
        if (!file.is_open()) { // 如果文件无法打开
            qDebug()<<"无法打开文件"+filename+"/n"; // 输出调试信息
            continue; // 跳过该文件
        }

        int page_num;
        string line;
        bool isChapter_begin = true;

        while (getline(file, line)) { // 按行读取文件内容
            if (line.substr(0,7) == "Chapter" || line.substr(0,7) == "CHAPTER") { // 如果是章节行
                TempContent.chapter = line; // 更新章节信息
            }
            else if ('0' < line[0] && line[0] <= '9' && line.size() < 4){ // 如果是页码行
                istringstream ss(line); // 创建字符串流对象
                ss >> page_num; // 读取页码
                TempContent.page = page_num + 1; // 更新页码信息
            }
            else { // 如果是内容行
                TempContent.content = line; // 更新内容信息
                text.push_back(TempContent); // 将内容存入 text 向量中
            }
        }
        file.close(); // 关闭文件
    }
}

// 搜索人名/地名在文本中的出现位置并记录相关信息
void searchNameInBooks(string info, vector<int> & s)    //查找信息
{
    int all_len = text.size(); // 获取 text 向量的大小
    string::size_type p;
    for (int i = 0; i < all_len; i++)
    {
        p = text[i].content.find(info); // 在内容中查找信息
        while (!(p == string::npos)){ // 如果找到信息
            s.push_back(i); // 记录位置
            p = text[i].content.find(info,p+1); // 继续查找下一个出现位置
        }

    }
}

// 搜索按钮点击事件处理函数
void MainWindow::on_pushButton_clicked()
{
    string info = ui->lineEdit_info->text().toStdString(); // 获取输入框中的搜索信息
    searchNameInBooks(info, search_Info); // 调用搜索函数
    if (!search_Info.empty()){ // 如果找到信息
        ui->tableWidget->setRowCount(search_Info.size()); // 设置表格行数
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); // 设置列宽自适应内容
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents); // 设置列宽自适应内容
        for (int i = 0; i < search_Info.size(); i++){
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1))); // 设置序号
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(info))); // 设置人名/地名
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(text[search_Info[i]].page))); // 设置页码
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(text[search_Info[i]].chapter))); // 设置章节
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(text[search_Info[i]].book))); // 设置书名
        }
    }
    else { // 如果找不到信息
        QMessageBox::warning(my,"警告","找不到呢>_<"); // 显示警告对话框
    }

}

// 表格单元格双击事件处理函数
void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    ui->label_content->setText(QString::fromStdString(text[search_Info[row]-1].content + text[search_Info[row]].content)); // 显示前后两行内容
}
