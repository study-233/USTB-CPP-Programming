#include <iostream>
using namespace std;

// 定义基类 Animal
class Animal {
public:
    // 定义虚函数 bark
    virtual void bark(){
        printf("...\n");
    }; // Pure virtual function
};

// Mouse 类继承自 Animal
class Mouse : public Animal {
public:
    // 实现 bark 函数
    void bark() {
        printf("\nzhi...zhi...\n");
    }
};

// Dog 类继承自 Animal
class Dog : public Animal {
public:
    // 实现 bark 函数
    void bark() {
        printf("\nwang...wang...\n");
    }
};
int main(){
    Animal a;
    Mouse m;
    Dog d;
    a.bark();
    m.bark();
    d.bark();
}