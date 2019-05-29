#include "hero.h"


//初始化英雄类
Hero::Hero(int id)
{
	File file;
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//创建一个临时string变量接收传入的id(转string类型)
	string tempId=std::to_string(id);
	string heroId=hero[tempId]["heroId"];
	this->heroHp=atoi(hero[heroId]["heroHp"].c_str());       //英雄生命值
	this->heroAtk=atoi(hero[heroId]["heroAtk"].c_str());	 //英雄基础攻击力
	this->heroDef=atoi(hero[heroId]["heroDef"].c_str());	 //英雄防御力
	this->heroName=hero[heroId]["heroName"];				 //英雄名字
	this->heroInfo=hero[heroId]["heroInfo"];				 //英雄的基本信息
	this->weapon=NULL;										 //默认英雄是赤手空拳的		
	
}

//攻击模式 选择攻击哪个Boss
void Hero::Attack(Boss *boss)
{
	int damage=0;   //伤害
	int cri=0;		//暴击
	int suck=0;		//吸血
	int frozen=0;	//冰冻效果
	if(this->weapon==NULL)
	{
		damage=this->heroAtk;	//赤手空拳的攻击力
	}
	else
	{
		damage=this->heroAtk+this->weapon->getBaseAtk();    //装备后的攻击力

		//是否产生暴击
		cri=this->weapon->getWeaponCri();

		//是否产生吸血
		suck=this->weapon->getWeaponSuck();

		//是否产生冰冻
		frozen=this->weapon->getWeaponFrozen();
	}
	//如果产生暴击效果
	if(cri)
	{
		cout<<"英雄 <"<<this->heroName<<"> 攻击怪物时候产生了暴击!"<<endl;
		damage+=cri;
	}

	//如果产生吸血效果
	if(suck)
	{
		cout<<"英雄 <"<<this->heroName<<"> 攻击怪物时候产生吸血效果!  吸血生命值为"<<suck<<endl;
	}

	//如果产生冰冻效果
	if(frozen)
	{
		cout<<"英雄 <"<<this->heroName<<"> 攻击怪物时候产生冰冻效果! "<<endl;
	}

	//将武器产生的冰冻效果传值给怪物
	boss->ifFrozen=frozen;

	//对怪物造成的真实伤害
	damage=damage-boss->bossDef>0 ? damage-boss->bossDef : 1;

	//造成伤害后怪物的生命值
	boss->bossHp-=damage;

	//触发吸血效果英雄回血
	this->heroHp+=suck;

	//造成的伤害输出
	cout<<"英雄 <"<<this->heroName<<"> 对怪物 <"<<boss->bossName<<"> 造成的伤害为 : "<<damage<<endl;
}

//选择的武器
void Hero::HaveWeapon(Weapon *weapon)
{
	if(weapon==NULL)
	{
		return;
	}
	this->weapon=weapon;       //用类中的weapon装备选择的
	cout<<"系统提示：<"<<this->heroName<<">装备了< "<<this->weapon->weaponName<<">武器!"<<endl;
}


