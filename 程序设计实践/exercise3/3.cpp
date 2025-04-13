/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Point2D{
public:
    int x;
    int y;

    Point2D(int x,int y):x(x),y(y){}

};

class Creature{
public:
    string name;
    static int counter;
    int id;
    Point2D point;

    Creature(string name,int x,int y):name(name),id(counter++),point(x,y){}

    void printcreature(){
        cout<<"No. "<<id<<" creature "<<name<<" is at ("<<point.x<<", "<<point.y<<")";
        cout<<endl;
    }
    void move(int x,int y){
        point.x = x;
        point.y = y;
    }
};
int Creature::counter = 0;
int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    vector<Creature*> Creatures;

    string command, name;
    int x,y,id;
    while (cin >> command) {
        if (command == "n") {
            cin >> name >> x >> y;
            Creatures.push_back(new Creature(name,x,y));
        } 
        else if (command == "s") {
            cin >> id;
            Creature* creature = Creatures[id];
            creature->printcreature();
        }
        else if (command == "a") {
            for(auto creature : Creatures)
                creature->printcreature();
            cout<<endl;
        }
        else if (command == "m") {
            cin >> id >> x >> y;
            Creature* creature = Creatures[id];
            creature->move(x,y);

        }
        else if (command == "e")
            break;
    }

    // Clean up dynamic allocation
    for(auto creature : Creatures)
        delete creature;

    return 0;
}
