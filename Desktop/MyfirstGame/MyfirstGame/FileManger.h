#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

//�ļ�������
class File
{
public:

	//�������ݵĶ�ȡ
	void praselineVector(string firstline,vector<string>&v); 

	//����CSV�������
	void loadCSVDate(string fileName,map<string,map<string,string>>&maxString);


};