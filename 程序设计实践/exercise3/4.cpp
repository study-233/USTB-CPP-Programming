/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;
class MyStack{
    private:
        int m_array[10];
        int m_size = 0;
    public:
        bool push(int x){
            if(m_size<10){
                m_array[m_size]=x;
                m_size++;
                return true;
            }
            return false;
        }
        bool pop(){
            if(m_size>0){
                m_size--;
                return true;
            }
            return false;
        }
        void print(){
            int temp = 0;
            cout<<"( ";
            while(temp < m_size){
                cout<<m_array[temp]<<" ";
                temp++;
            }
            cout<<")";
        }

};
int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    MyStack stack;
    string command;
    int x;
    while (cin >> command) {
        if (command == "i") {
            cin>>x;
            stack.push(x);
        } 
        else if (command == "o") {
            if(!stack.pop()) cout<<"Can not pop empty stack";
        }
        else if (command == "s") {
            stack.print();
            break;
        }
    }

    return 0;
}
