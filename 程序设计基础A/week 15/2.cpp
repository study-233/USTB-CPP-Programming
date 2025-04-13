#include <iostream>
#include <cmath>

#define PI 3.1415926

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual double calculateCircumference() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height): width_(width), height_(height) {}

    double calculateArea() override {
        return width_ * height_;
    }

    double calculateCircumference() override {
        return 2 * (width_ + height_);
    }

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius): radius_(radius) {}

    double calculateArea() override {
        return PI * pow(radius_, 2);
    }

    double calculateCircumference() override {
        return 2 * PI * radius_;
    }

private:
    double radius_;
};

int main() {
    double width, height, radius;
    
    std::cin >> width >> height;
    Rectangle rectangle(width, height);
    std::cout << rectangle.calculateArea() << "\n";
    std::cout << rectangle.calculateCircumference() << "\n";

    std::cin >> radius;
    Circle circle(radius);
    std::cout << circle.calculateArea() << "\n";
    std::cout << circle.calculateCircumference() << "\n";

    return 0;
}