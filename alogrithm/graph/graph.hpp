#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <limits.h> //for 正无穷
#include "edge.hpp"

//无向图邻接表实现
template <typename T>
class Graph
{
public:
    std::map<T, std::set<Edge<T>>> adj; //邻接表//

    bool contains(const T &u); //判断顶点U是否在图中

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

    int largest_degree(); //求图中最大的度数

    int get_weight(const T &u, const T &v); //得到某两个顶点之间边的权重

    std::vector<T> get_vertices(); //得到图中所有顶点

    std::map<T, int> get_neighbours(const T &u); //得到顶点u的所有边

    void show();

    void dft_recursion(const T &u, std::set<T> &visited, std::vector<T> &result); /* 深度优先遍历递归辅助函数 */
    std::vector<T> depth_first_rec(const T &u);                                   /* 深度优先遍历递归法 */
    std::vector<T> depth_first_itr(const T &u);                                   /* 深度优先遍历迭代法*/
    std::vector<T> breadth_first(const T &u);                                     /* 广度优先遍历迭代法 */

    Graph<T> prim(T v); //prim最小生成树算法

    std::map<T, int> dijkstra(T start); //迪杰斯特拉算法
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
bool Graph<T>::contains(const T &u)
{
    return adj.find(u) != adj.end();
}
template <typename T>
bool Graph<T>::adjacent(const T &u, const T &v)
{
    if (contains(u) && contains(v) && u != v)
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
        std::set<Edge<T>> edge_list;
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
    if (contains(u) && contains(v))
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
    if (u == v || !contains(u) || !contains(v))
        return;

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
template <typename T>
int Graph<T>::num_edges()
{
    int count = 0;
    std::set<Edge<T>> vertex_set;

    for (auto vertex : adj)
    {
        vertex_set.insert(Edge<T>(vertex.first, 0));
        for (auto edge : vertex.second)
        {
            if (vertex_set.find(edge) != vertex_set.end())
                continue;
            count++;
        }
    }
    return count;
}
template <typename T>
int Graph<T>::largest_degree()
{
    if (num_vertices() == 0)
        return 0;

    unsigned max_degree = 0;
    for (auto vertex : adj)
    {
        if (vertex.second.size() > max_degree)
            max_degree = vertex.second.size();
    }
    return max_degree;
}
template <typename T>
int Graph<T>::get_weight(const T &u, const T &v)
{
    if (contains(u) && contains(v))
    {
        for (Edge<T> edge : adj[u])
            if (edge.vertex == v)
                return edge.weight;
    }
    return -1;
}
template <typename T>
std::vector<T> Graph<T>::get_vertices()
{
    std::vector<T> vertices;
    for (auto vertex : adj)
    {
        vertices.push_back(vertex.first);
    }
    return vertices;
}
template <typename T>
std::map<T, int> Graph<T>::get_neighbours(const T &u)
{
    std::map<T, int> neighbours;
    if (contains(u))
    {
        for (Edge<T> edge : adj[u])
            neighbours[edge.vertex] = edge.weight;
    }
    return neighbours;
}

template <typename T>
void Graph<T>::dft_recursion(const T &u, std::set<T> &visited, std::vector<T> &result)
{
    result.push_back(u);
    visited.insert(u);

    for (Edge<T> edge : adj[u])
        if (visited.find(edge.vertex) == visited.end())
            dft_recursion(edge.vertex, visited, result);
}
template <typename T>
std::vector<T> Graph<T>::depth_first_rec(const T &u)
{
    std::vector<T> result;
    std::set<T> visited;
    if (contains(u))
        dft_recursion(u, visited, result);
    return result;
}

template <typename T>
std::vector<T> Graph<T>::depth_first_itr(const T &u)
{
    std::vector<T> result;
    std::set<T> visited;
    std::stack<T> s;

    s.push(u);
    while (!s.empty())
    {
        T v = s.top();
        s.pop();

        if (visited.find(v) != visited.end())
            continue;

        visited.insert(v);
        result.push_back(v);

        for (auto w : adj[v])
        {
            if (visited.find(w.vertex) == visited.end())
            {
                s.push(w.vertex);
            }
        }
    }
    return result;
}
template <typename T>
std::vector<T> Graph<T>::breadth_first(const T &u)
{
    std::vector<T> result;
    std::set<T> visited;
    std::queue<T> q;

    q.push(u);
    while (!q.empty())
    {
        T v = q.front();
        q.pop();

        if (visited.find(v) != visited.end())
        {
            continue;
        }

        visited.insert(v);
        result.push_back(v);

        for (Edge<T> edge : adj[v])
        {
            if (visited.find(edge.vertex) == visited.end())
            {
                q.push(edge.vertex);
            }
        }
    }
    return result;
}

template <typename T>
Graph<T> Graph<T>::prim(T v)
{
    //最小生成树的创建
    Graph<T> min_spanning_tree;

    //在生成树中添加顶点
    min_spanning_tree.add_vertex(v);

    //设置带权重的队列，按第一个元素(权值)从小到大的排列
    std::priority_queue<std::pair<int, std::pair<T, T>>, std::vector<std::pair<int, std::pair<T, T>>>, std::greater<std::pair<int, std::pair<T, T>>>> q;

    std::set<T> visited;

    //入队：入队的元素是一个pair类型，第一个值是权重，第二个值也是pair
    //第二个pair里面第一个值是u(只在生成树中存在的顶点)第二个是v(只在原图中存在的点)

    for (auto neighbour : adj[v])
    {
        q.push(std::make_pair(neighbour.weight, std::make_pair(v, neighbour.vertex)));
    }

    while (!q.empty())
    {
        //队首元素出队
        auto front = q.top();
        q.pop();

        //获得已在生成树中的顶点u

        T u = front.second.first;

        //获得在原图中，但不在生成树中的顶点v
        T v = front.second.second;

        //如果顶点v已经访问则跳过本次循环
        if (visited.find(v) != visited.end())
            continue;
        else
            visited.insert(v);

        //在生成树中添加新的顶点v以及u和v之间的边
        min_spanning_tree.add_vertex(v);
        min_spanning_tree.add_edge(u, v, front.first);

        //依次将顶点V未访问过的邻居放入优先队列中
        for (auto neighbour : adj[v])
        {
            if (visited.find(neighbour.vertex) == visited.end())
            {
                q.push(std::make_pair(neighbour.weight, std::make_pair(v, neighbour.vertex)));
            }
        }
    }
    return min_spanning_tree;
}

template <typename T>
std::map<T, int> Graph<T>::dijkstra(T start)
{
    // 设置dis用来存放初始点到图中任何一个顶点的距离
    std::map<T, int> dis;

    // 设置带权重的队列，按每个pair的第一个元素进行从小到大的排列
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> q;

    for (T vertex : get_vertices())
    {
        // 设置初始顶点到自己的距离为0
        if (vertex == start)
            dis[start] = 0;
        // 设置初始顶点到其他顶点的距离为无穷大
        else
            dis[vertex] = INT_MAX;
    }

    // 设置集合visited来存放已经访问过的顶点
    std::set<T> visited;

    // 入队：入队的元素是一个pair类型，第一个值是权重，第二个值是顶点
    q.push(std::make_pair(0, start));

    while (!q.empty())
    {
        // 队首元素出队
        auto front = q.top();
        q.pop();

        // 获得当前顶点
        T u = front.second;

        // 如果该顶点已经访问过则跳过本此循环，否则存入到集合visited中表示已经访问过
        if (visited.find(u) != visited.end())
            continue;
        else
            visited.insert(u);

        // 获得到顶点u的最短路径"shortest_distance_to_u"，将此路径存入到dis结果中
        int shortest_distance_to_u = front.first;
        dis[u] = shortest_distance_to_u;

        // 依次访问顶点u尚未访问过的邻居
        for (auto v : adj[u])
        {
            if (visited.find(v.vertex) == visited.end())
            {
                // 从顶点u到邻居v的路径记为“distance_to_v”
                int distance_to_v = v.weight;
                q.push(make_pair(shortest_distance_to_u + distance_to_v, v.vertex));
            }
        }
    }
    return dis;
}