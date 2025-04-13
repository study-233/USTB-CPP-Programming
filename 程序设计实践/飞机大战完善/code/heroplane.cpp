#include "heroplane.h"
#include"config.h"


void HeroPlane::HeroPlaneint(){
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化飞机坐标
    m_X = (GAME_WIDTH - m_Plane.width()) * 0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    for(int i = 0;i < BULLET_NUM;i++){
        m_Bullets[i].Bulletint();
    }
}
void HeroPlane::setPosition(int x, int y){
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::shoot(){
    //累加时间间隔记录
    m_Recorder++;

    //如果记录的数字，未达到发射子弹的时间间隔，这个子弹不会发射
    if(m_Recorder < BULLET_INTERVAL){
        return;
    }
    //达到发射时间
    m_Recorder = 0;
    for(int i=0;i<BULLET_NUM;i++){
        //如果这是空闲的子弹，进行发射
        if(m_Bullets[i].m_Free){
            //将空闲状态改为假
            m_Bullets[i].m_Free = false;
            //设置子弹坐标
            m_Bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
            m_Bullets[i].m_Y = m_Y - 10;
            break;
        }
    }
}
