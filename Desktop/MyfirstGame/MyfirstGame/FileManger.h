#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

//文件管理类
class File
{
public:

	//单行数据的读取
	void praselineVector(string firstline,vector<string>&v); 

	//加载CSV里的内容
	void loadCSVDate(string fileName,map<string,map<string,string>>&maxString);


};