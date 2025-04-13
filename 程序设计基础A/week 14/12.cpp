/**/
#include <bits/stdc++.h>
using namespace std;
class Publication{
    protected:
        string name;
        int price;
        string date;
    public:
        void inputData(string name_,int price_,string date_){
            name=name_;
            price=price_;
            date=date_;
        }
        void display(){
            cout<<name<<" "<<price<<" "<<date<<'\n';
        }
};
class book:public Publication{
    private:
        int page;
    public:
        void inputData(string name_,int price_,string date_,int page_){
            name=name_;
            price=price_;
            date=date_;
            page=page_;
        }
        void display(){
            cout<<name<<" "<<price<<" "<<date<<" "<<page<<'\n';
        }
};
class Tape:public Publication{
    private:
        string playtime;
    public:
        void inputData(string name_,int price_,string date_,string playtime_){
            name=name_;
            price=price_;
            date=date_;
            playtime=playtime_;
        }
        void display(){
            cout<<name<<" "<<price<<" "<<date<<" "<<playtime<<'\n';
        }     
};


int main(){
    //freopen("E:\\CPPCODE\\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    Publication p;
    book b;
    Tape t;
    p.inputData("Publication", 120, "1999-2-1");
    p.display();
    b.inputData("Book", 30, "2009-1-1", 300);
    b.display();
    t.inputData("Tape", 15, "2003-5-1", "00:48:10");
    t.display();    
}