//mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindows;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_account_clicked();

    void on_pushButton_deposit_clicked();

    void on_pushButton_showaccount_clicked();

    void on_pushButton_withdraw_clicked();

    void on_pushButton_Confirmdays_clicked();

    void on_pushButton_NextMonth_clicked();

    void on_pushButton_query_clicked();

    void on_pushButton_clear_clicked();

private:
    static void cmdprocess(char cmd);   //处理命令
    static void read_cmd();
    Ui::mainwindows *ui;
    static MainWindow *my;
    static void show_alert();   //显示提示信息
    static void refreshdate();     //更新日期
};
#endif // MAINWINDOW_H
