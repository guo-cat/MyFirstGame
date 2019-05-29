#include "Knife.h"
#include "FileManger.h"
//初始化小刀属性
Knife::Knife()
{
	File file;
	map<string,map<string,string>>m;
	file.loadCSVDate("./heroweapon.csv",m);
	string id=m["1"]["weaponId"];
	this->weaponName=m[id]["weaponName"];							 //武器名字
	this->baseAtk=atoi(m[id]["weaponAtk"].c_str());					 //武器基础攻击
	this->weaponCriPlus=atoi(m[id]["weaponCriPlus"].c_str());		 //武器暴击系数
	this->weaponCriRate=atoi(m[id]["weaponCriRate"].c_str());		 //武器暴击率
	this->weaponSuckPlus=atoi(m[id]["weaponSuckPlus"].c_str());		 //武器吸血系数
	this->weaponSuckRate=atoi(m[id]["weaponSuckRate"].c_str());		 //武器吸血率
	this->weaponFrozenRate=atoi(m[id]["weaponFrozenRate"].c_str());  //武器冰冻率
}

//获取基础伤害
int Knife::getBaseAtk()
{
	return this->baseAtk;
}

//获取暴击效果 当大于>0时候触发暴击
int  Knife::getWeaponCri()
{
	if(isTrigger(this->weaponCriRate))
	{
		return this->baseAtk*this->weaponCriPlus;
	}
	else
	{
		return 0;
	}
}

//获取吸血效果 当大于0时候触发吸血
int Knife::getWeaponSuck()
{
	if(isTrigger(this->weaponSuckRate))
	{
		return this->baseAtk*this->weaponSuckPlus;
	}
	else
	{
		return 0;
	}
}

//获取冰冻效果 当大于0出发冰冻效果
int  Knife::getWeaponFrozen()
{
	if(isTrigger(this->weaponFrozenRate))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//触发概率
bool  Knife::isTrigger(int rate)
{
	int num=rand()%100+1;   //随机数1~100
	if(num<rate)
	{
		return true;
	}
	else
	{
		return false;
	}
}