template<typename T>
class Edge{
    public:
    T vertex;
    int weight;

    Edge(T neighbour_vertex){
        this->vertex=neighbour_vertex;
        this->weight=0;
    }
    Edge(T neighbour_vetex, int weight){
        this->vertex=neighbour_vetex;
        this->weight=weight;
    }
    bool operator<(const Edge& obj)const{
        return obj.vertex>vertex;
    }
    bool operator ==(const Edge&obj)const{
        return obj.vertex==vertex;
    }
};