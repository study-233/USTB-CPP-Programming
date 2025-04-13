#ifndef BULLETTOOL_H
#define BULLETTOOL_H
#include <QRect>
#include <QPixmap>
class BulletTool
{
public:
    BulletTool();
    void init(QString w);//拿w路径初始化资源图片和坐标
    void New_Speed();//更新移动方向的函数
    void updatepostion();//更新位置的函数

public:
    int m_x,m_y;//位置
    int speed_x,speed_y;//移动速度
    int record;//销毁时间
    int force = 1;
    QPixmap img;//道具的图片资源
    QRect m_rect;

};

#endif // BULLETTOOL_H

