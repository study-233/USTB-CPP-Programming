#include <iostream>
using namespace std;
void move(char A, char C,int n){ //输出
    cout<<A<<" to "<<C<<endl;
}
void Hanno(char A, char B, char C, int n) //n表示移动几个圆盘
{
	if (n == 1){
		move(A, C, n); //只剩一个时直接直接移动
	}
	else{
		Hanno(A, C, B, n - 1); //将n-1个圆盘从A柱借助于C柱移动到B柱上
		move(A, C, n); //将A柱子最后一个圆盘移动到C柱上
		Hanno(B, A, C, n - 1); //将n-1个圆盘从B柱借助于A柱移动到C柱上
	}
}
int main(){
    int n;
    cin>>n;
    Hanno('A','B','C',n);
	system("");
}
