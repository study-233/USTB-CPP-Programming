#include<iostream>
#include<cmath>
using namespace std;

// 定义圆类
class Circle{
private:
    int radius; // 私有数据成员半径
public:
    Circle(int r):radius(r){} // 构造函数
    float getArea(){return M_PI*radius*radius;} // 获取圆面积
};

// 定义桌子类
class Table{
private:
    int height; // 私有数据成员高度
public:
    Table(int h):height(h){} //构造函数
    int getHeight(){return height;} // 获取高度
};

// 定义圆桌类
class RoundTable : public Circle, public Table{
private:
    string color;//私有数据成员颜色
public:
    RoundTable(int r, int h, string c):Circle(r), Table(h), color(c){} //构造函数
    string getColor(){ return color;} // 获取颜色
};

int main(){
    int r, h;
    string c;
    cin >> r >> h >> c;
    RoundTable table(r, h, c);//创建一个圆桌对象
    cout << table.getArea() << endl;
    cout << table.getHeight() << endl;
    cout << table.getColor() << endl;
    return 0;
}