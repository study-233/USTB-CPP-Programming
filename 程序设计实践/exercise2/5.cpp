/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
static int handle = 0;
static int sum = 0;//用来计算总内存

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int T, MaxMem;
    cin >> T >> MaxMem;
    vector<int> arr(T + 1, -1); //用来存放句柄
    vector<int> sizeArr(T + 1); //用来存放句柄对应的size
    for (int i = 0; i < T; i++) {
        string str;
        int size = 0;
        cin>>str;
        if (str == "def") {
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] == -1) {
                    sum -= sizeArr[j];
                }
            }
        }
        else{
            cin>>size;
            if (str == "new") {
                sum += size;
                if (sum <= MaxMem) {
                    handle++;
                    arr[handle] = size;
                    sizeArr[handle] = size;
                    cout << handle << endl;
                } 
                else {
                    sum -= size;
                    cout << "NULL" << endl;
                }
            } 
            else if (str == "del") {
                if(arr[size] != -1 && size < T) arr[size] = -1; //-1表示删除了该句柄
                else cout << "ILLEGAL_OPERATION" << endl;

            }
        }
    }
    return 0;
}