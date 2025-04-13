//bullet.h
#ifndef BULLET_H
#define BULLET_H

#include<QPixmap>
#include<QRect>
#include"config.h"
#include<QPainter>

class Bullet
{
public:

    void Bulletint();

    //更新子弹坐标
    void updataPosition();

    //子弹资源对象
    QPixmap m_Bullet;

    //子弹坐标
    int m_X;
    int m_Y;

    //子弹移动速度
    int m_Speed;

    //子弹是否闲置
    bool m_Free;

    //子弹的矩形边框（用于碰撞检测）
    QRect m_Rect;

    //
    int force = 1;
};

#endif // BULLET_H
