#ifndef CONFIG_H
#define CONFIG_H

/**************游戏配置数据***************/
#define GAME_HEIGHT 768 //高度
#define GAME_WIDTH 512 //宽度
#define GAME_TITLE "飞机大战 V1.0" //标题
#define GAME_RES_PATH "./plane.rcc" //rcc文件路径
#define GAME_ICON ":res/app.ico"
#define GAME_RATE 10 //定时器刷新时间间隔，单位是毫秒


/**************地图配置数据***************/
#define MAP_PATH ":/res/img_bg_level_2.jpg" //地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

/**************飞机配置属性**************/
#define HERO_PATH ":/res/hero2.png" //飞机路径
#define HERO_HP 5; //飞机血量

/***********子弹配置数据**************/
#define BULLET_PATH ":/res/bullet_1.png" //子弹图片路径
#define BULLET_SPEED 5 //子弹移动速度
#define BULLET_NUM 30 //弹匣中子弹的数量
#define BULLET_INTERVAL 15 //子弹发射间隔
#define BUULLETTOOL ":/res/bullet_14.png"

/***********敌机配置文件***************/
#define ENEMY_PATH ":res/img-plane_3.png"  //敌机资源图片
#define ENEMY_SPEED 5  //敌机移动速度
#define ENEMY_NUM 20  //敌机总数量
#define ENEMY_INTERVAL 30  //敌机出场时间间隔
#define EMEMY_HP 5 //敌机血量

/************爆炸配置数据***************/
#define BOMB_PATH  ":/res/bomb-%1.png"  //爆炸资源图片，百分号%是占位符参数，是不确定的数
#define BOMB_NUM  20  //爆炸数量
#define BOMB_MAX  7  //爆炸图片最大索引
#define BOMB_INTERVAL  20  //爆炸切图时间间隔

/*************音效配置数据****************/
#define SOUND_BACKGROUND  ":/res/bg.wav"  //背景音乐
#define SOUND_BOMB  ":/res/bomb.wav"  //爆炸音效

/*************开始界面数据****************/
#define START_PATH ":/res/lk.png" //开始图片

#endif // CONFIG_H
