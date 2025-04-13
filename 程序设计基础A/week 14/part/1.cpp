#include<iostream>
using  namespace  std;  
class  Shape                                                                      //基类Shape的定义
{  
public:  
        Shape(){}  
        ~Shape(){}  
        double  getArea()const;
};  
double  Shape::getArea()  const
{  
        return  0.0;
}  
//start
//Circle类、Rectangle类、Square类的定义
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r = 0) : radius(r) {}
    ~Circle() {}

    double getArea() const {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double a;
    double b;
public:
    Rectangle(double a = 0, double b = 0) : a(a), b(b) {}
    ~Rectangle() {}

    double getArea() const {
        return a * b;
    }
};

class Square : public Rectangle {
public:
    Square(double a = 0) : Rectangle(a, a) {} // Square is just a special Rectangle
    ~Square() {}
};

//end
int  main()  
{  
      //start
        //  创建Circle类对象，radius为3.5
Circle circle(3.5);

              //  创建Rectangle类对象，两条边分别为5,10
Rectangle rectangle(5, 10);

        //  创建square类对象，边长为5
Square square(5);

    //end
cout<<"The  area  of  the  circle  is  "<<circle.getArea()<<endl;  
cout<<"The  area  of  the  rectangle  is  "<<rectangle.getArea()<<endl;  
cout<<"The  area  of  the  Square  is  "<<square.getArea()<<endl;
return  0;
}