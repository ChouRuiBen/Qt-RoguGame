#ifndef PARAMETER_H
#define PARAMETER_H

/*****************基础参数**********************/
#define GAME_WIDTH 1675 //界面实际宽度
#define GAME_WIDTH_RECT 1575 //地图矩形框宽度
#define GAME_HEIGHT 943 //界面高度
#define GAME_HEIGHT_RECT 890 //地图矩形框高度
#define GAME_ICON ":/weapons/eve.png" //游戏图标
#define GAME_BACKGROUND ":/scenes/map.png" //背景位置
#define GAME_TiTLE "Rogulike Game" //名字
#define GAME_HZ 10 //刷新率
#define HOLD_TIME 180 //坚持时间

/*****************障碍物参数*********************/
#define LOCATION_BARRIO ":/scenes/castle.png" //障碍位置
#define BARRIO_WIDTH 260 //障碍宽度
#define BARRIO_HEIGHT 210 //障碍高度

/*****************子弹参数**********************/
#define BULLET_NUM 32 //弹夹数量
#define BULLET_INTERVAL 100 //发射间隔
#define BULLET_SPEED 5 //子弹速度

/*****************敌人参数***********************/
#define NORMALENEMY_NUM 20 //普通敌人储备数量
#define ELITENEMY_NUM 4 // 精英怪储备数量
#define ENEMY_INTERVAL 200 //敌人出现间隔

#define BOSS_HP 800 // BOSS血量
#define BOSS_ATK 15 // BOSS攻击力
#define BOSS_SPEED 0.5 // BOSS速度

#define GIANT_HP 200 // 精英怪血量
#define GIANT_ATK 10 // 精英怪攻击力
#define GIANT_SPEED 1 // 精英怪速度
#define GIANT_EP 50 // 精英怪经验

#define GHOST_HP 40 // 普通怪血量
#define GHOST_ATK 5 // 普通怪攻击力
#define GHOST_SPEED 4 // 普通怪速度
#define GHOST_EP 10 // 普通怪经验

/*****************商店参数***********************/
#define PRICE 1000 //商品价格
#define DROP_NUM 30

#endif // PARAMETER_H
