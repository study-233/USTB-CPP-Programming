/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void merge(int* a, int s, int m, int e) {
	int* b = new int[e - s + 1];    //用 new 申请一个辅助函数
	int i = s, j = m + 1, k = 0;    // k为 b 数组的小标
	
    while (i <= m && j <= e){
		if (a[i] <= a[j]){
			b[k++] = a[i++];     //按从小到大存放在 b 数组里面
		}
		else{
			b[k++] = a[j++];
		}
	}

	while (i <= m)        // j 序列结束，将剩余的 i 序列补充在 b 数组中 
		b[k++] = a[i++];
	while (j <= e)       // i 序列结束，将剩余的 j 序列补充在 b 数组中 
		b[k++] = a[j++];

	k = 0;  //从小标为 0 开始传送
	for (int i = s; i <= e; i++)  //将 b 数组的值传递给数组 a
	{
		a[i] = b[k++];
	}
	delete[]b;     // 辅助数组用完后，将其的空间进行释放（销毁）
}
void mergesort(int* a, int s, int e) //归并排序
{
	if (s < e)
	{
		int m = (s + e) / 2;
		mergesort(a, s, m);          //对 a[s,m]进行排序
		mergesort(a, m + 1, e);    //对 a[m+1,e]进行排序
		merge(a, s, m, e);       //进行合并操作
	}
}
int main()
{
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout<<endl;
	mergesort(a, 0, n-1);
	cout << "after sorting:" << endl;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}