#include "mainscene.h"
#include <QDebug>
#include <QTimer>
#include <QString>
#include "config.h"
#include "ui_mainscene.h"
#include <QKeyEvent>
#include <QMessageBox>

MainScene::MainScene(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{

    //调用初始化场景
    initScene();

    // 连接定时器的timeout信号与游戏更新槽
    connect(&m_Timer, &QTimer::timeout, this, &MainScene::gameUpdate);

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    // 停止定时器，确保重新开始时不会叠加
    if (m_Timer.isActive()) {
        m_Timer.stop();
    }

    // 重新初始化UI
    ui->setupUi(this);
    this->grabKeyboard();

    // 初始化随机数
    srand(static_cast<unsigned int>(time(nullptr)));

    // 设置按钮属性
    ui->btn->resize(200, 80);
    ui->btn->move((width() - 200) / 2, height() / 2 - 40);
    ui->btn->setStyleSheet("QPushButton{border-image:url(:/res/lk.png);border-style:outset;background-color:transparent;}");

    // 初始化分数
    score_ = 0;
    ui->score->move(0, 0);
    ui->score->resize(80, 20);
    ui->score->setText(QString("得分:%1").arg(score_));
    ui->score->setStyleSheet("QLabel{color:rgb(255,255,255);}");
    ui->score->setFont(QFont("Timers", 15, 0));

    // 初始化血量
    ui->hp->move(width() - 80, 0);
    ui->hp->resize(80, 20);
    ui->hp->setText(QString("血量:%1").arg(m_Hero.hp));
    ui->hp->setStyleSheet("QLabel{color:rgb(255,255,255);}");
    ui->hp->setFont(QFont("Timers", 15, 0));

    // 提示信息
    ui->info->resize(400, 120);
    ui->info->move((width() - 200) / 2 - 100, height() / 2 - 300);
    ui->info->setText("用鼠标操控飞机\n按ESC暂停\n按下面的开始游戏按钮开始游玩\n");

    connect(ui->btn, &QPushButton::clicked, [=]() {
        playGame();
        ui->btn->hide();
        ui->info->hide();
    });

    // 设置窗口的固定尺寸
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    // 设置标题
    setWindowTitle(GAME_TITLE);

    // 加载图标
    setWindowIcon(QIcon(GAME_ICON));

    // 定时器设置
    m_Timer.setInterval(GAME_RATE);

    // 初始化敌机出场时间间隔
    m_recorder = 0;
    m_Hero.hp = HERO_HP;  // 重置英雄飞机血量

    // 初始化英雄飞机和敌机
    m_Hero.HeroPlaneint();
    for (int i = 0; i < ENEMY_NUM; i++) {
        m_enemys[i].EnemyPlaneint();
    }

    // 初始化爆炸
    for (int i = 0; i < BOMB_NUM; i++) {
        m_bombs[i].Bombint();
    }

    // 初始化地图
    m_map.Mapint();

}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        if(m_Timer.isActive()){
            m_Timer.stop();
            backSound.stop();
            QMessageBox msgBox;
            msgBox.setText("已暂停");
            QPushButton *yesButton = msgBox.addButton(tr("继续"), QMessageBox::YesRole);
            QPushButton *noButton = msgBox.addButton(tr("退出"),QMessageBox::NoRole);

            msgBox.exec();

            if (msgBox.clickedButton() == yesButton) {
                m_Timer.start();
                backSound.play();
            } else if (msgBox.clickedButton() == noButton) {
                this->hide();
            }
        }
    }
}

void MainScene::playGame()
{

    bullettool.init(BUULLETTOOL);

    //启动背景音乐
    backSound.setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));
    backSound.play();

    //启动定时器
    m_Timer.start();
}

void MainScene::gameUpdate()
{
    // 敌机出场
    enemyToScene();
    // 更新游戏中元素的坐标
    updataPosition();
    // 绘制到屏幕中
    update();
    // 碰撞检测的调用
    colisionDetection();
}

void MainScene::updataPosition()
{
    //更新地图的坐标
    m_map.mapPosition();

    //    //测试
    //    temp_Bullet.m_Free = false;
    //    temp_Bullet.updataPosition();

    //发射子弹
    m_Hero.shoot();

    //计算所有非空闲子弹的当前坐标
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空闲，计算发射的位置
        if (m_Hero.m_Bullets[i].m_Free == false) {
            m_Hero.m_Bullets[i].updataPosition();
        }
    }

    //敌机出场
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
        }
    }

    //计算爆炸的播放的图片
    for (int i = 0; i < BOMB_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            m_bombs[i].updateInfo();
        }
    }

    bullettool.updatepostion();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_Hero.m_X, m_Hero.m_Y, m_Hero.m_Plane);


    //    //测试子弹
    //    painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);

    //绘制子弹
    for (int i = 0; i < BULLET_NUM; i++) {
        //如果非空闲，绘制
        if (m_Hero.m_Bullets[i].m_Free == false) {
            painter.drawPixmap(m_Hero.m_Bullets[i].m_X,
                               m_Hero.m_Bullets[i].m_Y,
                               m_Hero.m_Bullets[i].m_Bullet);
        }
    }
    //绘制敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);

            QBrush red_brush(QColor("#F20900"));                        //把刷子设置为红色
            painter.setBrush(red_brush);                                //应用刷子
            float rate = 1.0 * m_enemys[i].now_hp / m_enemys[i].sum_hp; //计算比例
            painter.drawRect(m_enemys[i].m_X,
                             m_enemys[i].m_Y,
                             rate * m_enemys[i].m_enemy.width(),
                             m_enemys[i].m_enemy.height() * 0.2); //绘制矩形
        }
    }

    //绘制爆炸
    for (int i = 0; i < BOMB_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            painter.drawPixmap(m_bombs[i].m_X,
                               m_bombs[i].m_Y,
                               m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
    if(bullettool.record >= 0)
        painter.drawPixmap(bullettool.m_x,bullettool.m_y,bullettool.img);
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_Hero.m_Rect.width() * 0.5;
    int y = event->y() - m_Hero.m_Rect.height() * 0.5;

    //边界检测
    if (x <= 0) {
        x = 0;
    }
    if (x >= GAME_WIDTH - m_Hero.m_Rect.width()) {
        x = GAME_WIDTH - m_Hero.m_Rect.width();
    }
    if (y <= 0) {
        y = 0;
    }
    if (y > +GAME_HEIGHT - m_Hero.m_Rect.height()) {
        y = GAME_HEIGHT - m_Hero.m_Rect.height();
    }

    m_Hero.setPosition(x, y);
}

void MainScene::enemyToScene()
{
    m_recorder++;
    //未到达出场间隔，直接return
    if (m_recorder < ENEMY_INTERVAL) {
        return;
    }
    m_recorder = 0;
    for (int i = 0; i < ENEMY_NUM; i++) {
        //如果是空闲的敌机，出场
        if (m_enemys[i].m_Free) {
            m_enemys[i].m_Free = false;

            //坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::colisionDetection()
{
    //遍历所有非空闲的敌机
    for (int i = 0; i < ENEMY_NUM; i++) {
        //如果时空闲的飞机，执行下一次循环
        if (m_enemys[i].m_Free)
            continue;
        if(m_enemys[i].m_Rect.intersects(m_Hero.m_Rect)){
            m_enemys[i].m_Free = true;
            m_Hero.hp--;
            if(m_Hero.hp == 0){
                m_Timer.stop();
                backSound.stop();
                QMessageBox msgBox;
                msgBox.setText("游戏结束，是否选择再来一把");
                QPushButton *yesButton = msgBox.addButton(tr("是"), QMessageBox::YesRole);
                QPushButton *noButton = msgBox.addButton(tr("退出"),QMessageBox::NoRole);
                msgBox.exec();

                if (msgBox.clickedButton() == yesButton) {
                    initScene();
                } else if (msgBox.clickedButton() == noButton) {
                    this->close();
                }

                m_Hero.hp = HERO_HP;
            }
            ui->hp->setText(QString("血量:%1").arg(m_Hero.hp));
            break;
        }
        //便利所有的非空闲的子弹
        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_Hero.m_Bullets[j].m_Free)
                continue;

            QRect res = m_Hero.m_Bullets[j].m_Rect;
            //走到这一步说明飞机和子弹都是非空闲的
            //如果飞机和子弹相交，发生碰撞
            if (res.intersects(m_enemys[i].m_Rect)) {
                m_enemys[i].now_hp-=m_Hero.m_Bullets[j].force;
                m_Hero.m_Bullets[j].m_Free = true;

                if (m_enemys[i].now_hp <= 0) {
                    m_enemys[i].m_Free = true;
                    score_++;
                    ui->score->setText(QString("得分:%1").arg(score_));
                    //播放爆炸效果
                    for (int k = 0; k < BOMB_NUM; k++) {
                        if (m_bombs[k].m_Free) {
                            //播放爆炸的音效
                            bombSound.setSource(QUrl::fromLocalFile(SOUND_BOMB));
                            bombSound.play();
                            //空闲的爆炸，可以播放
                            m_bombs[k].m_Free = false;
                            //更新爆炸坐标
                            m_bombs[k].m_X = m_enemys[i].m_X;
                            m_bombs[k].m_Y = m_enemys[i].m_Y;
                            break;
                        }
                    }
                    m_enemys[i].now_hp = m_enemys[i].sum_hp;
                }
            }
        }
    }
    QRect res = m_Hero.m_Rect;
    if(res.intersects(bullettool.m_rect)){
        for (int j = 0; j < BULLET_NUM; j++) {
            m_Hero.m_Bullets[j].m_Bullet = bullettool.img;
            m_Hero.m_Bullets[j].force = bullettool.force;
        }
        bullettool.record = 1;
    }
}
