#include <iostream>
#include <cstring>
using namespace std;

class Simple {
private:
    char*  m_name;
public:
    ~Simple(){
        delete [] m_name;
        m_name  = 0;
    }

    Simple(char* val) {
        m_name = new char[strlen(val)+1];
        strcpy(m_name, val);
    }

    Simple(const Simple& rhs) {
        m_name = new char[strlen(rhs.m_name)+1];
        strcpy(m_name, rhs.m_name);
    }

    char* getName() {
        return m_name;
    }
};


class Base {
private:
    char  m_x;
public:
    Base(char  val) : m_x(val) {}

    char getX() const {
        return m_x;
    }
};


class Derived: public Base {
private:
    double m_y;
    Simple m_s;
public:
   Derived(char* name, double y=100, char x='X') : Base(x), m_y(y), m_s(name) {}

    Derived(const Derived& obj) : Base(obj.getX()), m_y(obj.m_y), m_s(obj.m_s) {}

    void print() {
        cout  <<  m_s.getName()  <<  "  "
            <<  m_y  <<  "  "
            <<  getX()  <<  endl;
    }
};


int main()
{
    Derived  d1("Tom",  90.7,  'M');
    d1.print();

    Derived  d2(d1);
    d2.print();

    Derived  d3("Jerry",  88.5);
    d3.print();

    Derived  d4("Mary");
    d4.print();

    return 0;
}