#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// 结构体用于存储查询结果
class Text {
public:
    int page;       // 页码
    string chapter; // 章节
    string book;    // 书名
    string content; // 内容
};

vector <Text> text;
Text TempContent;

// 读取文件，存储到text中
void readBooks(const vector<string>& filenames) {

    for (string filename : filenames) {
        TempContent.book = filename; // 假设文件名即为书名
        TempContent.page = 1;
        TempContent.chapter = "Chapter Zero";


        ifstream file;
        file.open(filename+".txt");
        if (!file.is_open()) {
            cerr << "无法打开文件：" << filename << endl;
            continue;
        }

        int page_num;
        string line;
        bool isChapter_begin = true;

        while (getline(file, line)) {
            if (line.substr(0,7) == "Chapter" || line.substr(0,7) == "CHAPTER") {
                TempContent.chapter = line;
            }
            else if ('0' < line[0] && line[0] <= '9' && line.size() < 4){
                istringstream ss(line);
                ss >> page_num;
                TempContent.page = page_num + 1;
            }
            else {
                TempContent.content = line;
                text.push_back(TempContent);
            }
        }
        file.close();
    }
}

// 函数用于搜索人名/地名在文本中的出现位置并记录相关信息
void searchNameInBooks(string info, vector<int> & s)    //查找信息
{
    int all_len = text.size();
    string::size_type p;
    for (int i = 0; i < all_len; i++)
    {
        p = text[i].content.find(info);
        while (!(p == string::npos)){
            s.push_back(i);
            p = text[i].content.find(info,p+1);
        }

    }
}

// 函数用于显示查询结果
void displayResults(vector<int> s, string info) {
    cout << "序号       人名/地名       页码       章节       书名" << endl;
    for (int i = 0; i < s.size(); i++)
        cout << "  "
             << i + 1           << "\t"
             << info            << "\t"
             << text[s[i]].page       << "\t"
             << text[s[i]].chapter    << "\t"
             << text[s[i]].book   << endl;
}

int main() {
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

    // 读取文本文件内容
    readBooks(filenames);

    // 用户输入要查询的人名/地名
    string info;
    cout << "请输入要查询的人名/地名：";
    cin >> info;

    // 搜索人名/地名
    vector<int> search_Info;
    searchNameInBooks(info, search_Info);

    // 显示查询结果
    if (!search_Info.empty())
    {
        displayResults(search_Info, info);
        cout << endl << "请输入要显示的段落的序号: " << endl;
        while (1)
        {
            int x = 1;
            cin >> x;
            if (x == 0)
                break;
            cout << endl << text[search_Info[x - 1]-1].content << endl << text[search_Info[x - 1]].content << endl;
            cout << endl << "若要继续显示结果，请继续输入序号，否则输入 0:" << endl;
        }
    }
    else
        cout << "无法查询到 ! ! !" << endl;
    return 0;

}

