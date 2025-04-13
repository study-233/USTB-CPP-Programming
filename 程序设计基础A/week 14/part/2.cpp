#include<iostream>
using  namespace  std;

class vehicle {
private:
    int wh;
    float we;

public:
    // 基类的构造函数
    vehicle(int wh_, float we_) : wh(wh_), we(we_) {}

    // Getter and Setter方法
    int getWheels() { return wh; }
    float getWeight() { return we; }
    void setWheels(int wh_) { wh = wh_; }
    void setWeight(float we_) { we = we_; }

    virtual void print() {
        cout << "车轮数为：" << getWheels() << "个" << endl
             << "车重为：" << getWeight() << "吨" << endl;
    }
};

class car : public vehicle {
private:
    int pa;

public:
    // 派生类的构造函数
    car(int wh, float we, int pa_) : vehicle(wh, we), pa(pa_) {}

    int getPassengers() { return pa; }
    void setPassengers(int pa_) { pa = pa_; }

    virtual void print() {
        cout<<"小车：\n";
        vehicle::print();
        cout << "载人数为：" << getPassengers() << "个" << endl;
    }
};

class truck : public vehicle {
private:
    int pa;
    float pay;

public:
    // 派生类的构造函数
    truck(int wh, float we, int pa_, float pay_)
        : vehicle(wh, we), pa(pa_), pay(pay_) {}

    int getPassengers() { return pa; }
    float getPayload() { return pay; }
    void setPassengers(int pa_) { pa = pa_; }
    void setPayload(float pay_) { pay = pay_; }

    virtual void print() {
        cout<<"卡车：\n";
        vehicle::print();
        cout << "载人数为：" << getPassengers() << "个" << endl
             << "载重为：" << getPayload() << "吨" << endl;
    }
};

int main() {
        int  vWH;
        float  vWE;
        cin  >>  vWH  >>  vWE;
        vehicle  ve1(vWH,vWE);
        ve1.print();
        int  cPA;
        cin  >>  vWH  >>  vWE  >>  cPA;
        car  car1(vWH,vWE,cPA);
        car1.print();
        double  tPay;
        cin  >>  vWH  >>  vWE  >>  cPA  >>  tPay;
        truck  tr1(vWH,vWE,cPA,tPay);
        tr1.print();
        return  0;
}