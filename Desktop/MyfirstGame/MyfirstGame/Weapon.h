//武器类
#pragma once
#include <iostream>
using namespace std;
#include <string>
class Weapon
{
public:
	//获取基础伤害
	virtual int getBaseAtk()=0;

	//获取暴击效果 当大于>0时候触发暴击
	virtual int getWeaponCri()=0;

	//获取吸血效果 当大于0时候触发吸血
	virtual int getWeaponSuck()=0;

	//获取冰冻效果 当大于0出发冰冻效果
	virtual int getWeaponFrozen()=0;

	//触发概率
	virtual bool isTrigger(int rate)=0;

public:
	string weaponName;    //武器名字
	int baseAtk;          //武器基础伤害
	int weaponCriPlus;    //武器暴击系数
	int weaponCriRate;	  //武器暴击率
	int weaponSuckPlus;   //武器吸血系数
	int weaponSuckRate;   //武器吸血率
	int weaponFrozenRate; //武器冰冻率
	
};