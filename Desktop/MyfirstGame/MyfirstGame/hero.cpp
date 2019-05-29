#include "hero.h"


//��ʼ��Ӣ����
Hero::Hero(int id)
{
	File file;
	map<string,map<string,string>>hero;
	file.loadCSVDate("./hero.csv",hero);

	//����һ����ʱstring�������մ����id(תstring����)
	string tempId=std::to_string(id);
	string heroId=hero[tempId]["heroId"];
	this->heroHp=atoi(hero[heroId]["heroHp"].c_str());       //Ӣ������ֵ
	this->heroAtk=atoi(hero[heroId]["heroAtk"].c_str());	 //Ӣ�ۻ���������
	this->heroDef=atoi(hero[heroId]["heroDef"].c_str());	 //Ӣ�۷�����
	this->heroName=hero[heroId]["heroName"];				 //Ӣ������
	this->heroInfo=hero[heroId]["heroInfo"];				 //Ӣ�۵Ļ�����Ϣ
	this->weapon=NULL;										 //Ĭ��Ӣ���ǳ��ֿ�ȭ��		
	
}

//����ģʽ ѡ�񹥻��ĸ�Boss
void Hero::Attack(Boss *boss)
{
	int damage=0;   //�˺�
	int cri=0;		//����
	int suck=0;		//��Ѫ
	int frozen=0;	//����Ч��
	if(this->weapon==NULL)
	{
		damage=this->heroAtk;	//���ֿ�ȭ�Ĺ�����
	}
	else
	{
		damage=this->heroAtk+this->weapon->getBaseAtk();    //װ����Ĺ�����

		//�Ƿ��������
		cri=this->weapon->getWeaponCri();

		//�Ƿ������Ѫ
		suck=this->weapon->getWeaponSuck();

		//�Ƿ��������
		frozen=this->weapon->getWeaponFrozen();
	}
	//�����������Ч��
	if(cri)
	{
		cout<<"Ӣ�� <"<<this->heroName<<"> ��������ʱ������˱���!"<<endl;
		damage+=cri;
	}

	//���������ѪЧ��
	if(suck)
	{
		cout<<"Ӣ�� <"<<this->heroName<<"> ��������ʱ�������ѪЧ��!  ��Ѫ����ֵΪ"<<suck<<endl;
	}

	//�����������Ч��
	if(frozen)
	{
		cout<<"Ӣ�� <"<<this->heroName<<"> ��������ʱ���������Ч��! "<<endl;
	}

	//�����������ı���Ч����ֵ������
	boss->ifFrozen=frozen;

	//�Թ�����ɵ���ʵ�˺�
	damage=damage-boss->bossDef>0 ? damage-boss->bossDef : 1;

	//����˺�����������ֵ
	boss->bossHp-=damage;

	//������ѪЧ��Ӣ�ۻ�Ѫ
	this->heroHp+=suck;

	//��ɵ��˺����
	cout<<"Ӣ�� <"<<this->heroName<<"> �Թ��� <"<<boss->bossName<<"> ��ɵ��˺�Ϊ : "<<damage<<endl;
}

//ѡ�������
void Hero::HaveWeapon(Weapon *weapon)
{
	if(weapon==NULL)
	{
		return;
	}
	this->weapon=weapon;       //�����е�weaponװ��ѡ���
	cout<<"ϵͳ��ʾ��<"<<this->heroName<<">װ����< "<<this->weapon->weaponName<<">����!"<<endl;
}


