#include "DragonKnife.h"
#include "FileManger.h"
//��ʼ��С������
DragonKnife::DragonKnife()
{
	File file;
	map<string,map<string,string>>m;
	file.loadCSVDate("./heroweapon.csv",m);
	string id=m["3"]["weaponId"];
	this->weaponName=m[id]["weaponName"];							 //��������
	this->baseAtk=atoi(m[id]["weaponAtk"].c_str());					 //������������
	this->weaponCriPlus=atoi(m[id]["weaponCriPlus"].c_str());		 //��������ϵ��
	this->weaponCriRate=atoi(m[id]["weaponCriRate"].c_str());		 //����������
	this->weaponSuckPlus=atoi(m[id]["weaponSuckPlus"].c_str());		 //������Ѫϵ��
	this->weaponSuckRate=atoi(m[id]["weaponSuckRate"].c_str());		 //������Ѫ��
	this->weaponFrozenRate=atoi(m[id]["weaponFrozenRate"].c_str());  //����������
}

//��ȡ�����˺�
int DragonKnife::getBaseAtk()
{
	return this->baseAtk;
}

//��ȡ����Ч�� ������>0ʱ�򴥷�����
int  DragonKnife::getWeaponCri()
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

//��ȡ��ѪЧ�� ������0ʱ�򴥷���Ѫ
int DragonKnife::getWeaponSuck()
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

//��ȡ����Ч�� ������0��������Ч��
int  DragonKnife::getWeaponFrozen()
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

//��������
bool  DragonKnife::isTrigger(int rate)
{
	int num=rand()%100+1;   //�����1~100
	if(num<rate)
	{
		return true;
	}
	else
	{
		return false;
	}
}