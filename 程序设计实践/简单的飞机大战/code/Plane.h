//
// Created by Andy on 24-6-12.
//

#ifndef PLANE_PLANE_H
#define PLANE_PLANE_H
#include <vector>
#include <algorithm>

using namespace std;

// 定义战场的大小
const int HEIGHT = 35;
const int WIDTH = 55;

// 飞机位置结构
struct Position {
    double x, y;
};

// 子弹类
struct Bullet {
    Position pos;
    int speedCounter;
    Bullet(int x, int y) : pos{x, y}, speedCounter(0) {}
};

// 飞机类
class Plane {
public:
    Position pos;
    vector<Bullet> bullets;

    Plane(double x, double y) : pos{x, y} {}

    void move(double dx, double dy);
    void shoot(bool isEnemy = false);
    void moveBullets(bool isEnemy = false, int speed = 1);

};


#endif //PLANE_PLANE_H
