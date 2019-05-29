//小刀类
#pragma once
#include <iostream>
using namespace std;
#include "Weapon.h"
class Knife :public Weapon
{
public:
	//初始化小刀武器
	Knife();

	//获取基础伤害
	virtual int getBaseAtk();

	//获取暴击效果 当大于>0时候触发暴击
	virtual int getWeaponCri();

	//获取吸血效果 当大于0时候触发吸血
	virtual int getWeaponSuck();

	//获取冰冻效果 当大于0出发冰冻效果
	virtual int getWeaponFrozen();

	//触发概率
	virtual bool isTrigger(int rate);
};
