#include "Plane.h"

//
// Created by Andy on 24-6-12.
//
void Plane::move(double dx, double dy) {
    pos.x += dx;
    pos.y += dy;
    if (pos.x < 0) pos.x = 0;
    if (pos.x >= WIDTH - 5) pos.x = WIDTH - 5;
    if (pos.y < 0) pos.y = 0;
    if (pos.y >= HEIGHT - 3) pos.y = HEIGHT - 3;
}

void Plane::shoot(bool isEnemy) {
    if (isEnemy) {
        bullets.emplace_back(pos.x + 2, pos.y + 3);
    } else {
        bullets.emplace_back(pos.x + 2, pos.y - 1);
    }
}

void Plane::moveBullets(bool isEnemy, int speed) {
    for (auto& bullet : bullets) {
        bullet.speedCounter++;
        if (bullet.speedCounter >= speed) {
            bullet.pos.y += (isEnemy ? 0.8 : -1);
            bullet.speedCounter = 0;
        }
    }
    bullets.erase(remove_if(bullets.begin(), bullets.end(), [](Bullet b) { return b.pos.y < 0 || b.pos.y >= HEIGHT; }), bullets.end());
}