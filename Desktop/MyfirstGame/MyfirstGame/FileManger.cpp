#include "FileManger.h"


//单行数据的读取
void File::praselineVector(string firstline,vector<string>&v)
{
	//将读取的文件存储到vector文件中
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


//实现加载CSV文件
void File::loadCSVDate(string fileName,map<string,map<string,string>>&maxString)
{
	//读文件
	ifstream ifs(fileName);

	//判断是否打开了文件
	if(!ifs.is_open())
	{
		cout<<"文件打开失败请重新打开！"<<endl;
		return;
	}

	//测试检验输出第一行
	string firstline;
	ifs>>firstline;
	//cout<<firstline<<endl;


	//将单行数据封装成一个函数
	vector<string>v;
	praselineVector(firstline,v);
	
	//遍历测试
	/*for(vector<string>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<endl;
	}*/

	//先定义一个大的map容器
	//map<string,map<string,string>> maxString;

	//取出其他的数据 
	string data;
	while(ifs>>data)
	{
		//cout<<data<<endl;
		//将其他数据存储在vector容器中
		vector<string>dataVector;
		praselineVector(data,dataVector);

		//先完成一个小map容器
		map<string,string>smallString;
		for(int i=0;i<v.size();i++)
		{
			smallString.insert(make_pair(v[i],dataVector[i]));
		}
		
		//再将其存入到大容器中
		maxString.insert(make_pair(dataVector[0],smallString));
	}
}