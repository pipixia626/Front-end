#include "schedule.h"
#include <algorithm>

bool operator<(const request &r1, const request &r2)
{
    return r1.finish < r2.finish;
}
void schedule::setNum(const int &n)
{
    this->n = n;
}

void schedule::init()
{
    cout << "输入请求的起始时间，结束时间，权重" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> reqs[i].start >> reqs[i].finish >> reqs[i].value;
    }
}

//根据结束时间大小进行排序，并对p[i]做记录
void schedule::sortReq()
{
    sort(reqs + 1, reqs + n + 1); //根据结束时间对所有请求排序

    /*for (int i = 1; i <= n; i++) {
		cout << reqs[i].start<<reqs[i].finish<<reqs[i].value << endl;
	}*/

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            if (reqs[j].finish <= reqs[i].start)
            {
                p[i] = j;
                break;
            }
        }
    }
}
//动态规划算法
void schedule::dpschedule()
{
    optimal[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (optimal[p[i]] + reqs[i].value >= optimal[i - 1]) //装reqs[i]大于不装reqs[i]
        {
            record[i][0] = 1;                           //装上
            optimal[i] = optimal[p[i]] + reqs[i].value; //获取价值
            record[i][1] = p[i];
        }
        else
        {
            optimal[i] = optimal[i - 1]; //不装
            record[i][0] = 0;
            record[i][1] = i - 1;
        }
    }
}

void schedule::getRes()
{
    cout << "请求响应序号：" << endl;
    for (int i = n; i > 0; i = record[i][1])
    {
        if (record[i][0] == 1)
        {
            cout << i << "->";
        }
    }
    cout << endl;
    cout << "最佳价值: " << optimal[n] << endl;
}
