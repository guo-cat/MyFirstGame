#include <iostream>
using namespace std;
#include "FileManger.h"
#include "Knife.h"
#include "YitianSword.h"
#include "DragonKnife.h"
#include "Boss.h"
#include "hero.h"
#include <ctime>

//PK函数
void Finghting()
{
	File file;
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//游戏开始界面
	cout<<"-----欢迎来到渣渣辉贪玩蓝月-------"<<endl;
	cout<<"请选择英雄："<<endl;

	//格式化
	char buf[1024];
	sprintf(buf,"1、%s<%s>",hero["1"]["heroName"].c_str(),hero["1"]["heroInfo"].c_str());
	cout<<buf<<endl;
	
	sprintf(buf,"2、%s<%s>",hero["2"]["heroName"].c_str(),hero["2"]["heroInfo"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"3、%s<%s>",hero["3"]["heroName"].c_str(),hero["3"]["heroInfo"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"4、%s<%s>",hero["4"]["heroName"].c_str(),hero["4"]["heroInfo"].c_str());
	cout<<buf<<endl;

	int select=0;	//选择自己先选的选项
	cin>>select;
	getchar();		//缓冲区 接受/n

	Hero heroMan(select);
	cout<<"您选择的英雄为："<<heroMan.heroName<<endl;

	cout<<"请选择武器："<<endl;

	map<string,map<string,string>>heroweapon;
	file.loadCSVDate("./heroweapon.csv",heroweapon);

	cout<<"1、赤手空拳"<<endl;
	sprintf(buf,"2、%s",heroweapon["1"]["weaponName"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"3、%s",heroweapon["2"]["weaponName"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"4、%s",heroweapon["3"]["weaponName"].c_str());
	cout<<buf<<endl;

	Weapon *weapon=NULL;     //默认初始化赤手空拳

	cin>>select;
	getchar();    //缓冲区

	switch (select)
	{
	case 1:
		cout<<"你真膨胀拿拳头怼！"<<endl;
		break;
	case 2:
		weapon=new Knife;
		break;
	case 3:
		weapon=new YitianSword;
		break;
	case 4:
		weapon=new DragonKnife;
		break;
	default:
		break;
	}

	//将选择的装备 装备
	heroMan.HaveWeapon(weapon);

	cout<<"下面将随机遇到BOSS!"<<endl;
	int bossId=rand()%4+1;
	Boss boss(bossId);

	int rount=1;   //记录第几个回合
	while(true)
	{
		getchar();
		system("cls");   //清空当前界面
		cout<<"-------当前为第"<<rount<<"个回合-----------"<<endl;

		//PK开始由英雄开始攻击
		heroMan.Attack(&boss);

		//Boss后开始攻击
		boss.FinghtHero(&heroMan);

		//描述当前英雄状态
		if(heroMan.heroHp<=0)
		{
			heroMan.heroHp=0;
			cout<<"当前英雄<"<<heroMan.heroName<<"> 剩下的生命值为："<<heroMan.heroHp<<endl;
		}
		else
		{
			cout<<"当前英雄<"<<heroMan.heroName<<"> 剩下的生命值为："<<heroMan.heroHp<<endl;
		}

		//描述当前BOSS的状态
		if(boss.bossHp<=0)
		{
			boss.bossHp=0;
			cout<<"当前怪物<"<<boss.bossName<<"> 剩下的生命值为："<<boss.bossHp<<endl;
		}
		else
		{
			cout<<"当前怪物<"<<boss.bossName<<"> 剩下的生命值为："<<boss.bossHp<<endl;
		}

		//判断英雄生命值
		if(heroMan.heroHp<=0)
		{
			cout<<"该英雄已经死亡，游戏结束请再接再励!"<<endl;
			break;
		}

		//判断BOSS生命值
		if(boss.bossHp<=0)
		{
			cout<<"恭喜过关，boss已被杀死!"<<endl;
			break;
		}

		rount++;
	}

}


int main()
{
	/*File file;

	//英雄表
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//武器
	map<string,map<string,string>>heroweapon;
	file.loadCSVDate("./heroweapon.csv",heroweapon);

	//怪物
	map<string,map<string,string>>bossInfo;
	file.loadCSVDate("./boss.csv",bossInfo);

	//测试英雄信息
	cout<<"1号英雄名字 :"<<hero["1"]["heroName"]<<endl;
	cout<<"1号英雄攻击力 :"<<hero["1"]["heroAtk"]<<endl;
	cout<<"1号英雄信息 :"<<hero["1"]["heroInfo"]<<endl;
	cout<<"1号英雄防御力 :"<<hero["1"]["heroDef"]<<endl;

	//测试英雄武器表
	cout<<"1号武器名字 :"<<heroweapon["1"]["weaponName"]<<endl;
	cout<<"4号武器攻击力 :"<<heroweapon["4"]["weaponAtk"]<<endl;

	//测试boss信息
	cout<<"1号boss名字 :"<<bossInfo["1"]["bossName"]<<endl;
	cout<<"2号boss攻击力 :"<<bossInfo["2"]["bossAtk"]<<endl;
	cout<<"4号boss防御力 :"<<bossInfo["4"]["bossDef"]<<endl;

	//获取武器小刀的基本信息
	Weapon *knife=new Knife;
	cout<<"武器的名字 "<<knife->weaponName<<endl;
	cout<<"武器的基础攻击力 "<<knife->baseAtk<<endl;
	cout<<"武器的冰冻率 "<<knife->weaponFrozenRate<<endl;


	//获取武器倚天剑的基本信息
	Weapon *yitianSword=new YitianSword;
	cout<<"武器的名字 "<<yitianSword->weaponName<<endl;
	cout<<"武器的基本攻击力 "<<yitianSword->baseAtk<<endl;
	cout<<"武器的暴击率 "<<yitianSword->weaponCriRate<<endl;
	cout<<"武器的吸血系数 "<<yitianSword->weaponSuckPlus<<endl;


	//u获取武器屠龙刀的基本信息
	Weapon *dragonKnife=new DragonKnife;
	cout<<"武器的名字 "<<dragonKnife->weaponName<<endl;
	cout<<"武器的基本攻击力 "<<dragonKnife->baseAtk<<endl;
	cout<<"武器的暴击系数 "<<dragonKnife->weaponCriPlus<<endl;
	cout<<"武器的冰冻率 "<<dragonKnife->weaponFrozenRate<<endl;*/

	//产生随机种子
	srand((unsigned int)time(NULL));
	Finghting();

	system("pause");
	return 0;
}