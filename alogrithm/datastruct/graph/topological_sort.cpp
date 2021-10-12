#include <queue>
#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    int V;          //顶点个数
    list<int> *adj; //邻接表
    queue<int> q;   //维护一个入度为0的顶点的集合
    int *indegree;  //每个顶点的入度
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w); //添加边
    bool topological_sort();    //拓扑排序
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    indegree = new int[V]; //入度全为0
    for (int i = 0; i < V; ++i)
    {
        indegree[i] = 0;
    }
}

Graph::~Graph()
{
    delete[] adj;
    delete[] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
            q.push(i); //将所有入度为0的顶点入队
    }
    int count = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        ++count;

        //将所有v指向的顶点的入度减一，并将入度为0的顶点入栈
        list<int>::iterator beg = adj[v].begin();
        for (; beg != adj[v].end(); ++beg)
        {
            if (!(--indegree[*beg]))
                q.push(*beg); //入度为0 则入栈
        }
    }

    if (count < V)
        return false;
    else
        return true;
}