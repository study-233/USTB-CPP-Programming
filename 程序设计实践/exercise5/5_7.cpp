/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void quick_sort(int* n, int left,int right) {
	int i, j, temp;
	i = left;
	j = right;
	if (i > j){
		return;
	}
	else{
		temp = n[left];
		while (i != j) {
			while (n[j] >= temp && i < j)   //先向左移动j
				j--;
			while (n[i] <= temp && i < j)   //再向右移动i
				i++;
			if (i < j){        
				int num = n[i];
				n[i] = n[j];
				n[j] = num;
			}
		}
 
		//此时i与j相遇，就与temp交换
		int new_temp = n[i];
		n[i] = n[left];
		n[left] = new_temp;
	}
	//最后左右边依次进入到递归
	quick_sort(n, left, i - 1); //左边的数字都比temp要小
	quick_sort(n, i + 1, right);  //右边的数字都比temp要大
}
 
int main() {
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout<<endl;
	quick_sort(a, 0, n-1);
	cout << "after sorting:" << endl;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}
