//heroplane.h
#ifndef HEROPLANE_H
#define HEROPLANE_H

#include<QRect>
#include<QPixmap>
#include"bullet.h"
#include<QPainter>

class HeroPlane
{
public:

    //初始化
    void HeroPlaneint();

    //发射子弹
    void shoot();

    //设置飞机位置
    void setPosition(int x,int y);

    //飞机资源
    QPixmap m_Plane;

    //飞机坐标
    int m_X;
    int m_Y;

    //飞机的矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_Bullets[BULLET_NUM];

    //发射弹匣记录
    int m_Recorder;

    //HP
    int hp = HERO_HP;
};

#endif // HEROPLANE_H
