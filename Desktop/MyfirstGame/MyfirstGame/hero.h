//英雄类的创建
#pragma once
#include <iostream>
using namespace std;
#include "Weapon.h"
#include "FileManger.h"
#include <map>
#include "Boss.h"
class Boss;
class Hero
{
public:
	//初始化
	Hero(int id);

	//攻击模式 选择攻击哪个Boss
	void Attack(Boss *boss);

	//选择的武器
	void HaveWeapon(Weapon *weapon);

public:
	int heroAtk;				//英雄攻击力
	int heroHp;					//英雄生命值
	int heroDef;				//英雄防御力
	string heroName;		    //英雄名字
	string heroInfo;			//英雄基本信息
	Weapon *weapon;				//所拥有的武器
};