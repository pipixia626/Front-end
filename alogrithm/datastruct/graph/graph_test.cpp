#include "graph.hpp"

void test01(Graph<char> g)
{
    std::cout << "'A' 和 'D'之间边的权重为：" << g.get_weight('A', 'D') << std::endl;
    g.change_weight('A', 'D', 100);
    std::cout << "将'A' 和 'D'之间边的权重更改为100后，其权重为：" << g.get_weight('A', 'D') << std::endl;
    g.remove_weight('A', 'D');
    std::cout << "将'A' 和 'D'之间边的权重删除后，其权重为：" << g.get_weight('A', 'D') << std::endl;
    std::cout << "将'A' 和 'D'之间边的权重重新设置为5" << std::endl;
    g.change_weight('A', 'D', 5);

    std::cout << "顶点总数：" << g.num_vertices() << std::endl;
    std::cout << "边的总数：" << g.num_edges() << std::endl;

    std::cout << "图中包含'F'吗？" << (g.contains('F') ? "包含" : "不包含") << std::endl;
    std::cout << "图中包含'G'吗？" << (g.contains('G') ? "包含" : "不包含") << std::endl;
    std::cout << "'A'和'D'相邻吗？" << (g.adjacent('A', 'D') ? "相邻" : "不相邻") << std::endl;
    std::cout << "'B'和'E'相邻吗？" << (g.adjacent('B', 'E') ? "相邻" : "不相邻") << std::endl;
    std::cout << "顶点'A'的度数为： " << g.degree('A') << std::endl;
    std::cout << "最大度数为：" << g.largest_degree() << std::endl;

    auto vertices = g.get_vertices();
    std::cout << "图中的顶点分别为：";
    for (auto u : vertices)
        std::cout << " " << u;
    std::cout << std::endl;

    std::map<char, int> nbrs = g.get_neighbours('F');
    std::cout << "顶点F的邻接顶点ID及其权重为：";
    for (auto u : nbrs)
        std::cout << " (" << u.first << ": " << u.second << ")";
    std::cout << std::endl;
}

void test02(Graph<char>g){
    auto dft = g.depth_first_rec('A');
    std::cout << "从顶点A进行深度优先遍历（递归）: {";
    for (auto u : dft) std::cout << u << " ";
    std::cout << "}" << std::endl;

    std::vector<char> dft_itr = g.depth_first_itr('A');
    std::cout << "从顶点A进行深度优先遍历（迭代）: {";
    for (auto u : dft_itr) std::cout << u << " ";
    std::cout << "}" << std::endl;

    auto bft = g.breadth_first('A');
    std::cout << "从顶点A进行广度优先遍历: {";
    for (auto u : bft) std::cout << u << " ";
    std::cout << "}" << std::endl;

}
void test03(Graph<char> g) {
    std::cout << "生成的最小生成树如下：" << std::endl;
    Graph<char> result = g.prim('A');
    result.show();
}

int main()
{
    Graph<char> g;
    g.add_vertex('A');
    g.add_vertex('B');
    g.add_vertex('C');
    g.add_vertex('D');
    g.add_vertex('E');
    g.add_vertex('F');
    g.add_vertex('G');

    g.add_edge('A', 'B', 7);
    g.add_edge('A', 'D', 5);
    g.add_edge('B', 'C', 8);
    g.add_edge('B', 'D', 9);
    g.add_edge('B', 'E', 7);
    g.add_edge('C', 'E', 5);
    g.add_edge('D', 'E', 15);
    g.add_edge('D', 'F', 6);
    g.add_edge('E', 'F', 8);
    g.add_edge('E', 'G', 9);
    g.add_edge('F', 'G', 11);

    g.add_vertex('H');
    g.add_edge('B', 'H', 9);
    g.add_edge('A', 'H', 10);
    g.add_edge('D', 'H', 11);
    g.add_edge('A', 'H', 12);
    g.remove_vertex('H');
    std::cout << "打印图中顶点及其邻接表的详细信息如下" << std::endl;
    g.show();
    std::cout << std::endl;

    //test01(g);
    //test02(g);
    test03(g);
    return 0;
}