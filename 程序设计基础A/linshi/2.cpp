#include<iostream>
using namespace std;

class PoweredDevice
{
protected:
    int m_power;
public:
    PoweredDevice(int power) :m_power(power) {
    }
                    void  print(){
                              cout  <<  "PoweredDevice:  "  <<  m_power  <<  endl;
        }
};

class Scanner: public PoweredDevice
{
protected:
    int m_scan;
public:
    Scanner(int power, int scan): PoweredDevice(power), m_scan(scan) {
    }
    void print() {
        cout << "Scanner: " << m_power << " " << m_scan << endl;
    }
};

class Printer: public PoweredDevice
{
protected:
    int m_prin;
public:
    Printer(int power, int prin): PoweredDevice(power), m_prin(prin) {
    }
    void print() {
        cout << "Printer: " << m_power << " " << m_prin << endl;
    }
};


class Copier: public Scanner, public Printer
{
protected:
    int m_copy;
public:
    Copier(int power, int scan, int prin, int copy) : Scanner(power, scan), Printer(power, prin), m_copy(copy) {
    }
    void print() {
        cout << "Copier: " << Scanner::m_power << " " << m_scan << " " << m_prin << " " << m_copy << endl;
    }
};


int main() {
    Copier c1(1, 2, 3, 4);
    c1.print();

    Scanner s1(10, 20);
    s1.print();

    PoweredDevice p1(900);
    p1.print();
    return 0;
}