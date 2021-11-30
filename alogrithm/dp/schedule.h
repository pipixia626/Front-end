#pragma once
#include <iostream>
using namespace std;
const int Max_task = 10; //最大数目
typedef struct Request
{
	int start;	//开始
	int finish; //结束
	int value;	//权重
} request;

class schedule
{
public:
	void setNum(const int &n); //建立任务数
	void init();			   //数据准备
	void sortReq();			   //排序
	void dpschedule();		   //动态规划
	void getRes();			   //结果输出

private:
	request reqs[Max_task];
	int n;						   //n个数
	int p[Max_task] = {0};		   //
	int optimal[Max_task] = {0};   //选择
	int record[Max_task][2] = {0}; //记录
};
