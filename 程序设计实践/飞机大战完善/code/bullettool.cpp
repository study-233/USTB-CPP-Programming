#include "bullettool.h"
#include <QPixmap>
#include "config.h"
#include <QDebug>
BulletTool::BulletTool()
{
    record = 10000;
}

void BulletTool::init(QString w)
{
    img.load(w);
    force = 2;//威力
    m_x = rand()%GAME_WIDTH, m_y = rand()%(GAME_HEIGHT);
    if( m_x>=GAME_WIDTH-img.width() )   m_x = GAME_WIDTH-img.width();
    if( m_y>=GAME_HEIGHT-img.width() )   m_y = GAME_HEIGHT-img.width();

    m_rect.setWidth(img.width() );
    m_rect.setHeight(img.height() );
    m_rect.moveTo(m_x,m_y);
    speed_x = rand()%3+1, speed_y += rand()%3+1;
}

void BulletTool::New_Speed()//随机一个速度方向
{
    speed_x = rand()%2, speed_y = rand()%2;
    if( rand()%2==0 )   speed_x = -speed_x;//正负方向都需要随机
    if( rand()%2==0 )   speed_y = -speed_y;
    while( speed_x==0&&speed_y==0 )    speed_x = rand()%2, speed_y = rand()%2;
}

void BulletTool::updatepostion()
{
    if( --record==0 )   return;//不需要更新坐标了,同时也不需要绘制了
    //qDebug() << speed_x << " " << speed_y;
    m_x += speed_x, m_y += speed_y;
    if( m_x<0 ) m_x = 0,New_Speed();
    if( m_y<0 ) m_y = 0,New_Speed();
    if( m_x>GAME_WIDTH-img.width() )    m_x = GAME_WIDTH-img.width(),New_Speed();
    if( m_y>GAME_HEIGHT-img.height() )  m_y = GAME_HEIGHT-img.height(),New_Speed();
    m_rect.moveTo(m_x,m_y);
}

