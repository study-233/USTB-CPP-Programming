/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 9;

class PoweredDevice{
    public:
        static int PoweredDevice_num;
        PoweredDevice(){
            PoweredDevice_num++;
            cout<<"A new PoweredDevice is constructed."<<endl;
            cout<<"There are "<<PoweredDevice_num<<" PoweredDevices in total."<<endl;
        }
        virtual void print() = 0;
};
int PoweredDevice::PoweredDevice_num=0;

class Scanner : virtual public PoweredDevice{
    public:
        static int Scanner_num;
        Scanner(){
            Scanner_num++;
            cout<<"A new Scanner is constructed."<<endl;
            cout<<"There are "<<Scanner_num<<" Scanner in total."<<endl;
        }
        void print(){
            cout<<"Scanner"<<endl;
        }
};
int Scanner::Scanner_num=0;

class Printer : virtual public PoweredDevice{
    public:
        static int Printer_num;
        Printer(){
            Printer_num++;
            cout<<"A new Printer is constructed."<<endl;
            cout<<"There are "<<Printer_num<<" Printer in total."<<endl;
        }
        void print(){
            cout<<"Printer"<<endl;
        }

};
int Printer::Printer_num=0;

class Copier : virtual public Scanner,virtual public Printer{
    public:
        static int Copier_num;
        Copier(){
            Copier_num++;
            cout<<"A new Copier is constructed."<<endl;
            cout<<"There are "<<Copier_num<<" Copiers in total."<<endl;
        }
        void print(){
            cout<<"Copier"<<endl;
        }
};
int Copier::Copier_num=0;

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    vector<PoweredDevice *> PoweredDevices;

    string command;
    while (cin >> command) {
        if (command == "s") {
            PoweredDevices.push_back(new Scanner());
        } 
        else if (command == "p") {
            PoweredDevices.push_back(new Printer());
        }
        else if (command == "c") {
            PoweredDevices.push_back(new Copier());
        }
        else if (command == "e") {
            cout<<"The devices are:"<<endl;
            for(auto poweredDevice : PoweredDevices) 
                poweredDevice->print();
            break;
        }        
    }

    return 0;
}
