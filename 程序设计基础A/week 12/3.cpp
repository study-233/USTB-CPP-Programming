/*3. 矩形类*/
#include <bits/stdc++.h>
using namespace std;
class rectangle{
public:
    int r_longth;
    int r_wide;
    void getarea();
};

void rectangle::getarea(){
    cout<<r_longth*r_wide;
}

int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    rectangle A;
    cin>>A.r_longth>>A.r_wide;
    A.getarea();

}

