#include<iostream>
using namespace std;

//汽车类
class Vehicle {
protected:
    int wheels;
    double weight;
public:
    Vehicle(int w, double we) :wheels(w), weight(we) {}
    void display() {
        cout << "vehicle:" << endl;
        cout << "the number of cartwheel:" << wheels << endl;
        cout << "weight:" << weight << "ton" << endl;
    }
};

//小车类
class Car : public Vehicle {
protected:
    int passenger_load;
public:
    Car(int w, double we, int p) :Vehicle(w, we), passenger_load(p) {}
    void display() {
        cout << "car:" << endl;
        cout << "the number of cartwheel:" << wheels << endl;
        cout << "weight:" << weight << "ton" << endl;
        cout << "the number of available:" << passenger_load << endl;

    }
};

//卡车类
class Truck : public Vehicle {
protected:
    int passenger_load;
    double payload;
public:
    Truck(int w, double we, int p, double pay) :Vehicle(w, we), passenger_load(p), payload(pay) {}
    void display() {
        cout << "truck:" << endl;
        cout << "the number of cartwheel:" << wheels << endl;
        cout << "weight:" << weight << "ton" << endl;
        cout << "the number of available:" << passenger_load << endl;
        cout << "load:" << payload << "ton" << endl;
    }
};

int main() {
    Vehicle v(8, 5);
    Car c(4, 1, 5);
    Truck t(6, 8, 2, 10);
    v.display();
    c.display();
    t.display();
    return 0;
}