#include <iostream>
using namespace std;
// Animal类的定义
class Animal {
    public:
        virtual void what() = 0; // 纯虚函数
};

// Cat类的定义
class Cat : public Animal {
    public:
        void what() {
            cout << "Cat" << endl;
        }
};

// Leopard类的定义
class Leopard : public Animal {
    public:
        void what() {
            cout << "Leopard" << endl;
        }
};

int main() {
    Cat cat;
    Leopard leopard;

    cat.what();     // 输出"Cat"
    leopard.what(); // 输出"Leopard"

    return 0;
}