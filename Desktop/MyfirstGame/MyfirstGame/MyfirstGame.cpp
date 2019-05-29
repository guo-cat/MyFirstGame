#include <iostream>
using namespace std;
#include "FileManger.h"
#include "Knife.h"
#include "YitianSword.h"
#include "DragonKnife.h"
#include "Boss.h"
#include "hero.h"
#include <ctime>

//PK����
void Finghting()
{
	File file;
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//��Ϸ��ʼ����
	cout<<"-----��ӭ����������̰������-------"<<endl;
	cout<<"��ѡ��Ӣ�ۣ�"<<endl;

	//��ʽ��
	char buf[1024];
	sprintf(buf,"1��%s<%s>",hero["1"]["heroName"].c_str(),hero["1"]["heroInfo"].c_str());
	cout<<buf<<endl;
	
	sprintf(buf,"2��%s<%s>",hero["2"]["heroName"].c_str(),hero["2"]["heroInfo"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"3��%s<%s>",hero["3"]["heroName"].c_str(),hero["3"]["heroInfo"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"4��%s<%s>",hero["4"]["heroName"].c_str(),hero["4"]["heroInfo"].c_str());
	cout<<buf<<endl;

	int select=0;	//ѡ���Լ���ѡ��ѡ��
	cin>>select;
	getchar();		//������ ����/n

	Hero heroMan(select);
	cout<<"��ѡ���Ӣ��Ϊ��"<<heroMan.heroName<<endl;

	cout<<"��ѡ��������"<<endl;

	map<string,map<string,string>>heroweapon;
	file.loadCSVDate("./heroweapon.csv",heroweapon);

	cout<<"1�����ֿ�ȭ"<<endl;
	sprintf(buf,"2��%s",heroweapon["1"]["weaponName"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"3��%s",heroweapon["2"]["weaponName"].c_str());
	cout<<buf<<endl;

	sprintf(buf,"4��%s",heroweapon["3"]["weaponName"].c_str());
	cout<<buf<<endl;

	Weapon *weapon=NULL;     //Ĭ�ϳ�ʼ�����ֿ�ȭ

	cin>>select;
	getchar();    //������

	switch (select)
	{
	case 1:
		cout<<"����������ȭͷ��"<<endl;
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

	//��ѡ���װ�� װ��
	heroMan.HaveWeapon(weapon);

	cout<<"���潫�������BOSS!"<<endl;
	int bossId=rand()%4+1;
	Boss boss(bossId);

	int rount=1;   //��¼�ڼ����غ�
	while(true)
	{
		getchar();
		system("cls");   //��յ�ǰ����
		cout<<"-------��ǰΪ��"<<rount<<"���غ�-----------"<<endl;

		//PK��ʼ��Ӣ�ۿ�ʼ����
		heroMan.Attack(&boss);

		//Boss��ʼ����
		boss.FinghtHero(&heroMan);

		//������ǰӢ��״̬
		if(heroMan.heroHp<=0)
		{
			heroMan.heroHp=0;
			cout<<"��ǰӢ��<"<<heroMan.heroName<<"> ʣ�µ�����ֵΪ��"<<heroMan.heroHp<<endl;
		}
		else
		{
			cout<<"��ǰӢ��<"<<heroMan.heroName<<"> ʣ�µ�����ֵΪ��"<<heroMan.heroHp<<endl;
		}

		//������ǰBOSS��״̬
		if(boss.bossHp<=0)
		{
			boss.bossHp=0;
			cout<<"��ǰ����<"<<boss.bossName<<"> ʣ�µ�����ֵΪ��"<<boss.bossHp<<endl;
		}
		else
		{
			cout<<"��ǰ����<"<<boss.bossName<<"> ʣ�µ�����ֵΪ��"<<boss.bossHp<<endl;
		}

		//�ж�Ӣ������ֵ
		if(heroMan.heroHp<=0)
		{
			cout<<"��Ӣ���Ѿ���������Ϸ�������ٽ�����!"<<endl;
			break;
		}

		//�ж�BOSS����ֵ
		if(boss.bossHp<=0)
		{
			cout<<"��ϲ���أ�boss�ѱ�ɱ��!"<<endl;
			break;
		}

		rount++;
	}

}


int main()
{
	/*File file;

	//Ӣ�۱�
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//����
	map<string,map<string,string>>heroweapon;
	file.loadCSVDate("./heroweapon.csv",heroweapon);

	//����
	map<string,map<string,string>>bossInfo;
	file.loadCSVDate("./boss.csv",bossInfo);

	//����Ӣ����Ϣ
	cout<<"1��Ӣ������ :"<<hero["1"]["heroName"]<<endl;
	cout<<"1��Ӣ�۹����� :"<<hero["1"]["heroAtk"]<<endl;
	cout<<"1��Ӣ����Ϣ :"<<hero["1"]["heroInfo"]<<endl;
	cout<<"1��Ӣ�۷����� :"<<hero["1"]["heroDef"]<<endl;

	//����Ӣ��������
	cout<<"1���������� :"<<heroweapon["1"]["weaponName"]<<endl;
	cout<<"4������������ :"<<heroweapon["4"]["weaponAtk"]<<endl;

	//����boss��Ϣ
	cout<<"1��boss���� :"<<bossInfo["1"]["bossName"]<<endl;
	cout<<"2��boss������ :"<<bossInfo["2"]["bossAtk"]<<endl;
	cout<<"4��boss������ :"<<bossInfo["4"]["bossDef"]<<endl;

	//��ȡ����С���Ļ�����Ϣ
	Weapon *knife=new Knife;
	cout<<"���������� "<<knife->weaponName<<endl;
	cout<<"�����Ļ��������� "<<knife->baseAtk<<endl;
	cout<<"�����ı����� "<<knife->weaponFrozenRate<<endl;


	//��ȡ�������콣�Ļ�����Ϣ
	Weapon *yitianSword=new YitianSword;
	cout<<"���������� "<<yitianSword->weaponName<<endl;
	cout<<"�����Ļ��������� "<<yitianSword->baseAtk<<endl;
	cout<<"�����ı����� "<<yitianSword->weaponCriRate<<endl;
	cout<<"��������Ѫϵ�� "<<yitianSword->weaponSuckPlus<<endl;


	//u��ȡ�����������Ļ�����Ϣ
	Weapon *dragonKnife=new DragonKnife;
	cout<<"���������� "<<dragonKnife->weaponName<<endl;
	cout<<"�����Ļ��������� "<<dragonKnife->baseAtk<<endl;
	cout<<"�����ı���ϵ�� "<<dragonKnife->weaponCriPlus<<endl;
	cout<<"�����ı����� "<<dragonKnife->weaponFrozenRate<<endl;*/

	//�����������
	srand((unsigned int)time(NULL));
	Finghting();

	system("pause");
	return 0;
}