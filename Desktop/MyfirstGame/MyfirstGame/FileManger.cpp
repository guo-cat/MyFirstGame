#include "FileManger.h"


//�������ݵĶ�ȡ
void File::praselineVector(string firstline,vector<string>&v)
{
	//����ȡ���ļ��洢��vector�ļ���
	int start=0;
	int str=0;
	while (true)
	{
		int str=firstline.find(",",start);
		if(str==-1)
		{
			string vec=firstline.substr(start,firstline.size()-start);
			v.push_back(vec);
			break;
		}
		string vec=firstline.substr(start,str-start);
		v.push_back(vec);
		start=str+1;
	}
}


//ʵ�ּ���CSV�ļ�
void File::loadCSVDate(string fileName,map<string,map<string,string>>&maxString)
{
	//���ļ�
	ifstream ifs(fileName);

	//�ж��Ƿ�����ļ�
	if(!ifs.is_open())
	{
		cout<<"�ļ���ʧ�������´򿪣�"<<endl;
		return;
	}

	//���Լ��������һ��
	string firstline;
	ifs>>firstline;
	//cout<<firstline<<endl;


	//���������ݷ�װ��һ������
	vector<string>v;
	praselineVector(firstline,v);
	
	//��������
	/*for(vector<string>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<endl;
	}*/

	//�ȶ���һ�����map����
	//map<string,map<string,string>> maxString;

	//ȡ������������ 
	string data;
	while(ifs>>data)
	{
		//cout<<data<<endl;
		//���������ݴ洢��vector������
		vector<string>dataVector;
		praselineVector(data,dataVector);

		//�����һ��Сmap����
		map<string,string>smallString;
		for(int i=0;i<v.size();i++)
		{
			smallString.insert(make_pair(v[i],dataVector[i]));
		}
		
		//�ٽ�����뵽��������
		maxString.insert(make_pair(dataVector[0],smallString));
	}
}