## 开发日志

before 2023.5.23 : 学习Qt, 找素材 (学习资料来自[CSDN](https://www.csdn.net/),  [哔哩哔哩 (゜-゜)つロ 干杯~-bilibili](https://www.bilibili.com/).  素材来自[Kenney](https://www.kenney.nl/)的**Tiny Dungeon**与**board-game-icons**)

2023.5.23: 实现背景, 障碍物和人物的移动

2023.5.25: 实现怪物的生成和子弹移动

2023.5.29 代码重构 (约等于重来)

2023.5.29 完成界面间逻辑

2023.5.30 完成选角色和商店页面, 并实现商店的购买**(存在存档优化)**

2023.6.1 完成角色和障碍物的互动和子弹发射, 优化页面间逻辑

2023.6.2 完成普通敌人和近战精英敌人的实现和人物子弹的攻击效果

2023.6.3 完成远程精英敌人及其子弹发射的实现, 血条, 窗口逻辑优化

2023.6.4 实现BOSS , 尝试写强化但是失败

2023.6.5 实现了全局强化和局部强化, 存档

2023.6.6 收尾 + 掉落物



## 计划: 

### 1. 实现主界面(开始界面 + 帮助界面) 

### 2. 实现商店界面

​	**永久强化**:

 	1. 血瓶: 
 	2. 强化药水
 	3. 经验药水
 	4. 复活

### 3. 实现游玩页面

​	**游玩角色:** 

		1. 巫师: 实现子弹, 
		1. 骑士: 盾 + 扔匕首
		1. 屠夫: 扔斧头(穿透?)

​	**敌人:**

	1. 小怪: 幽灵
	1. 精英怪: 巨人(近战斧子, 远程子弹)
	1. BOSS: 巫师(远程子弹)

​	**局内强化**:

	1. 经验
	1. 金币
	1. 血量

​	**存档**

### 4. 优化