/**/
#include <bits/stdc++.h>
using namespace std;
class DOG{
    public:
        int age,weight;
        void GetAge();
        void SetAge(int);
        void GetWeight();
        void SetWeight(int);

};

void DOG::SetAge(int age_){
    age=age_;
}
void DOG::GetAge(){
    cout<<age<<" ";
}
void DOG::SetWeight(int weight_){
    weight=weight_;
}
void DOG::GetWeight(){
    cout<<weight<<" ";
}
int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    DOG DOG0;
    DOG0.SetWeight(10);
    DOG0.SetAge(2);
    DOG0.GetAge();
    DOG0.GetWeight();
    cout<<endl;
    DOG0.SetAge(30); 
    DOG0.GetAge();
    DOG0.GetWeight();   
}
