#include "Boss.h"

//初始化怪物类
Boss::Boss(int id)
{
	File file;
	map<string,map<string,string>>bossMap ;
	file.loadCSVDate("./boss.csv",bossMap);

	string tempId=std::to_string(id);
	string bossId=bossMap[tempId]["bossId"];

	this->bossName=bossMap[bossId]["bossName"];					//初始化怪物姓名
	this->bossAtk=atoi(bossMap[bossId]["bossAtk"].c_str());		//初始化怪物攻击力
	this->bossDef=atoi(bossMap[bossId]["bossDef"].c_str());		//初始化怪物的防御力
	this->bossHp=atoi(bossMap[bossId]["bossHp"].c_str());		//初始化怪物的生命值
	this->ifFrozen=NULL;									    //初始化怪物是否被冰冻，默认未被冰冻

}

//怪物攻击英雄
void Boss::FinghtHero(Hero *heroMan)
{
	if(ifFrozen)
	{
		cout<<"怪物<"<<this->bossName<<"> 被冰冻一回合停止攻击一次"<<endl;
		return;
	}
	else
	{
		//计算怪物攻击力减去英雄的防御的所造成的真实伤害
		int damage=this->bossAtk-heroMan->heroDef>0 ? this->bossAtk-heroMan->heroDef : 1;

		//计算英雄的生命值
		heroMan->heroHp-=damage;

		//提示怪物攻击了英雄并造成了多少伤害
		cout<<"该怪物 <"<<this->bossName<<"> 攻击了英雄 "<<heroMan->heroName<<" 并造成的伤害为 "<<damage<<endl;
	}
}
