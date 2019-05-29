#include "Boss.h"

//��ʼ��������
Boss::Boss(int id)
{
	File file;
	map<string,map<string,string>>bossMap ;
	file.loadCSVDate("./boss.csv",bossMap);

	string tempId=std::to_string(id);
	string bossId=bossMap[tempId]["bossId"];

	this->bossName=bossMap[bossId]["bossName"];					//��ʼ����������
	this->bossAtk=atoi(bossMap[bossId]["bossAtk"].c_str());		//��ʼ�����﹥����
	this->bossDef=atoi(bossMap[bossId]["bossDef"].c_str());		//��ʼ������ķ�����
	this->bossHp=atoi(bossMap[bossId]["bossHp"].c_str());		//��ʼ�����������ֵ
	this->ifFrozen=NULL;									    //��ʼ�������Ƿ񱻱�����Ĭ��δ������

}

//���﹥��Ӣ��
void Boss::FinghtHero(Hero *heroMan)
{
	if(ifFrozen)
	{
		cout<<"����<"<<this->bossName<<"> ������һ�غ�ֹͣ����һ��"<<endl;
		return;
	}
	else
	{
		//������﹥������ȥӢ�۵ķ���������ɵ���ʵ�˺�
		int damage=this->bossAtk-heroMan->heroDef>0 ? this->bossAtk-heroMan->heroDef : 1;

		//����Ӣ�۵�����ֵ
		heroMan->heroHp-=damage;

		//��ʾ���﹥����Ӣ�۲�����˶����˺�
		cout<<"�ù��� <"<<this->bossName<<"> ������Ӣ�� "<<heroMan->heroName<<" ����ɵ��˺�Ϊ "<<damage<<endl;
	}
}
