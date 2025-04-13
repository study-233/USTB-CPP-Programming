#include "enemyplane.h"


void EnemyPlane::EnemyPlaneint(){
    //敌机资源加载
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    m_X = -m_enemy.width();
    m_Y = 0;

    //敌机状态
    m_Free = true;

    //敌机速度
    m_Speed = ENEMY_SPEED;

    //敌机矩形边框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);

    //敌机血量
    sum_hp = EMEMY_HP;
    now_hp = sum_hp;
}
void EnemyPlane::updatePosition()
{
    //空闲状态敌机  不计算坐标
    if(m_Free){
        return;
    }
    m_Y+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //如果超出了屏幕，重置空闲状态
    if(m_Y>=GAME_HEIGHT + m_Rect.height()){
        m_Free = true;
        now_hp = sum_hp;
    }
}
