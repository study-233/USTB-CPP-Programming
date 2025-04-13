#include <iostream>
#include <stdio.h>
using namespace std;

double calcAvgScore(double scores[6]){
    double sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += scores[i];
    }
    return sum / 6;
}
int main(){
    //freopen("D:\\cppcode\\cppcode\\MOOC\\in.txt","r",stdin);
    double scores[6];

    // 读取6个学生的考试成绩
    for (int i = 0; i < 6; i++) {
        cin >> scores[i];
    }
    //调用函数计算并输出
    double avgScore = calcAvgScore(scores);
    cout << avgScore << endl;
    return 0;
}