#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include "edge.hpp"

//无向图邻接表实现
template <typename T>
class Graph
{
public:
    std::map<T, std::set<Edge<T>>> adj; //邻接表//

    bool constains(const T &u); //判断顶点U是否在图中

    bool adjacent(const T &u, const T &v); //判断顶点u和v是否相邻

    void add_vertex(const T &u); //添加顶点

    void add_edge(const T &u, const T &v, int weight); //添加边和权重

    void change_weight(const T &u, const T &v, int weight); //修改权重

    void remove_weight(const T &u, const T &v); //移除权重

    void remove_vertex(const T &u); //移除顶点

    void remove_edge(const T &u, const T &v); //移除边

    int degree(const T &u); //求顶点的度数

    int num_vertices(); //求图中顶点的总数

    int num_edges(); //求图中边的总数

    int largesr_degree(); //求图中最大的度数

    int get_weight(const T &u, const T &v); //得到某两个顶点之间边的权重

    std::vector<T> get_vertices(); //得到图中所有顶点

    std::map<T, int> get_neighbours(const T &u); //得到顶点u的所有边

    void show();
};

template <typename T>
void Graph<T>::show()
{
    for (const auto &u : adj)
    {
        std::cout << "顶点" << u.first << ":";
        for (const auto &v : adj[u.first])
            std::cout << "(相邻顶点:" << v.vertex << ",边的权重:" << v.weight << ")";
        std::cout << std::endl;
    }
}
template <typename T>
bool Graph<T>::constains(const T &u)
{
    return adj.find(u) != adj.end();
}
template <typename T>
bool Graph<T>::adjacent(const T &u, const T &v)
{
    if (constains(u) && constains(v) && u != v)
    {
        for (auto edge : adj[u])
            if (edge.vertex == v)
                return true;
    }
    return false;
}
template <typename T>
void Graph<T>::add_vertex(const T &u)
{
    if (!contains(u))
    {
        set<Edge<T>> edge_list;
        adj[u] = edge_list;
    }
}

template <typename T>
void Graph<T>::add_edge(const T &u, const T &v, int weight)
{
    if (!adjacent(u, v))
    {
        adj[u].insert(Edge<T>(v, weight));
        adj[v].insert(Edge<T>(u, weight));
    }
}
template <typename T>
void Graph<T>::change_weight(const T &u, const T &v, int weight)
{
    if (constains(u) && constains(v))
    {
        if (adj[u].find(Edge<T>(v)) != adj[u].end())
        {
            adj[u].erase(Edge<T>(v));
            adj[u].insert(Edge<T>(v, weight));
        }
        if (adj[v].find(Edge<T>(u)) != adj[v].end())
        {
            adj[v].erase(Edge<T>(u));
            adj[v].insert(Edge<T>(u, weight));
        }
    }
}

template <typename T>
void Graph<T>::remove_weight(const T &u, const T &v)
{
    if (contains(u) && contains(v))
    {
        if (adj[u].find(Edge<T>(v)) != adj[u].end())
        {
            adj[u].erase(Edge<T>(v));
            adj[u].insert(Edge<T>(v, 0));
        }

        if (adj[v].find(Edge<T>(u)) != adj[v].end())
        {
            adj[v].erase(Edge<T>(u));
            adj[v].insert(Edge<T>(u, 0));
        }
    }
}

template <typename T>
void Graph<T>::remove_vertex(const T &u)
{
    if (contains(u))
    {
        for (auto &vertex : adj)
        {
            if (vertex.second.find(Edge<T>(u)) != vertex.second.end())
                vertex.second.erase(Edge<T>(u));
        }
        adj.erase(u);
    }
}
template <typename T>
void Graph<T>::remove_edge(const T &u, const T &v)
{
    if (u == v || !constains(u) || !continue(v))
        return

            if (adj[u].find(Edge<T>(v) != adj[u].end()))
        {
            adj[u].erase(Edge<T>(v));
            adj[v].erase(Edge<T>(u));
        }
}
template <typename T>
int Graph<T>::degree(const T &u)
{
    if (contains(u))
        return adj[u].size();

    return -1; // 度数为-1说明图中没有该顶点
}
template <typename T>
int Graph<T>::num_vertices()
{
    return adj.size();
}