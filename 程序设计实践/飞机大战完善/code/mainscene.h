#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QIcon>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QSoundEffect>
#include <QTimer>
#include <QMainWindow>
#include "bomb.h"
#include "config.h"
#include "enemyplane.h"
#include "heroplane.h"
#include "map.h"
#include "bullettool.h"
#include <cstdlib>
#include <ctime>
#include <QLabel>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainScene *ui;
    int score_ = 0;

public:
    explicit MainScene(QMainWindow *parent = 0);
    ~MainScene();

    void keyPressEvent(QKeyEvent *event);

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    void gameUpdate();

    //更新所有游戏中元素的坐标
    void updataPosition();

    //绘制到屏幕中  （函数名称不能改，是个Qt绘图事件）
    void paintEvent(QPaintEvent *);

    //重写鼠标移动事件  （这个函数名是个系统函数，函数名不可改）
    void mouseMoveEvent(QMouseEvent *);

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_Hero;

    //道具
    BulletTool bullettool;

    //定时器
    QTimer m_Timer;

    //敌机出场
    void enemyToScene();

    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder = 0;

    //碰撞检测
    void colisionDetection();

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //背景音乐
    QSoundEffect backSound;

    //爆炸音乐
    QSoundEffect bombSound;
};

#endif // MAINSCENE_H
