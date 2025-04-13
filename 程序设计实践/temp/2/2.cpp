/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class CDog;

class DogOwner{
    public:
        string name;
        vector<CDog*> CDogs;
        int count=0;


        DogOwner(string name): name(name){}

        void view_dogs();
        void adopt_a_dog(CDog* dog);
        void transfer_a_dog(CDog* dog,DogOwner* owner);
};

class CDog{
    public:
        string name;
        string breed;
        DogOwner* owner;

        CDog(string name,string breed,DogOwner* owner_ = NULL): name(name),breed(breed),owner(owner_){
            if(owner){
                owner->CDogs.push_back(this);
                owner->count++;
            }
        }

        void print_info(bool flag)
        {
            cout<<name<<","<<breed<<","<<(owner ? owner->name : "no Owner");
        }

};

void DogOwner::view_dogs(){
    cout<<name<<"有"<<count<<"条狗"<<endl;
    for(int i=0;i<count;i++){
       CDogs[i]->print_info(true);
       cout<<endl;
    }
}

void DogOwner::adopt_a_dog(CDog* dog){
       if(count<10 && dog->owner==NULL){
        CDogs.push_back(dog);
        dog->owner = this ;
    }            
}

void DogOwner::transfer_a_dog(CDog* dog,DogOwner* owner){
    owner->CDogs.push_back(dog);
    CDogs.erase(find(CDogs.begin(),CDogs.end(),dog));
}
int main(){

    DogOwner owner1("Leon"), owner2("Mike"), owner3("Chan");  

/* 
主人有姓名， 有拥有的狗，本例子只测试了其中的一个构造函数，需要写两个构造函数，类似还需要支持如下调用
CDog d1("Henry"), d2("Jimmy");CDog* init_dogs[10] = {&d1, &d2};DogOwner m1("Sandy",init_dogs);

*/

    CDog dog1("Koko","Pomeranian",NULL);   //狗有姓名，品种，和所属的主人

    CDog dog2("Jack","Retriever");

    CDog dog3("Henry","Huskey",&owner3);

    //狗信息展示测试

    dog1.print_info(true); cout<<endl;    //能输出狗的信息，用","分隔 名字 品种 主人名字  如果没有主人， 对应主人名字的地方要写 no Owner

    dog2.print_info(true); cout<<endl;

    dog3.print_info(true); cout<<endl;

    //展示三位主人的狗拥有情况

    owner1.view_dogs(); owner2.view_dogs(); owner3.view_dogs();//输出多行：对用第1行：主人有几条狗，其他行：依次为每个狗的信息

    //领养测试

    owner1.adopt_a_dog(&dog1);   //要考虑：被认养的这只狗应该是没有主人的； 已经养了超过了10只狗，不能认养；

    owner1.adopt_a_dog(&dog3);

    owner1.adopt_a_dog(&dog2);

    //展示三位主人的犬只拥有情况

    owner1.view_dogs(); owner2.view_dogs(); owner3.view_dogs();

    //转移狗的所属关系测试

    owner1.transfer_a_dog(&dog2,&owner2);  //  转让狗要完成狗的所属关系的确认，如果原来有主人，需要接触与原来主人的所属关系。

    //展示三位主人的狗拥有情况

    owner1.view_dogs(); owner2.view_dogs(); owner3.view_dogs();

    return 0;}