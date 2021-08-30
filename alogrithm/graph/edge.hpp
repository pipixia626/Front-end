template<typename T>
class Edge{
    public:
    T vertext;
    int weight;

    Edge(T neighbour_vertex){
        this->vertext=neighbour_vertex;
        this->weight=0;
    }
    Edge(T neighbour_vetex, int weight){
        this->vertext=neighbour_vetex;
        this->weight=weight;
    }
    bool operator<(const Edge& obj)const{
        return obj.vertext>vertext;
    }
    bool operator ==(const Edge&obj)const{
        return obj.vertext==vertext;
    }
};