#include "Graph_for_Primo.h"


void Vertex::add_edge(const AdjEdge& adjEdge) {
    adj.push_back({adjEdge.to, adjEdge.weight});
}

void Vertex::add_edge(int to, int weight) {
    adj.push_back({to, weight});
}


void Vertex::to_stream(std::ostream& os) const {
    os << "Ребра для вершины: " << id << std::endl;
    os << "{Куда, вес}" << std::endl;

    for (const AdjEdge& ad : adj) {
        os << '{' << ad.to << ", " << ad.weight << "}; ";
    }
    os << std::endl;
}






Graph_for_Primo::Graph_for_Primo(int n) {
    for (int id = 1; id <= n; ++id) {
        vertices.push_back(Vertex(id));
    }
}


void Graph_for_Primo::add_edge(int to_vertex, int end_vertex, int weight) {
    vertices[to_vertex - 1].add_edge(end_vertex, weight);
    vertices[end_vertex - 1].add_edge(to_vertex, weight);
}

const std::vector<AdjEdge>& Graph_for_Primo::neighbors(int id) const {
    return vertices[id - 1].adj;
}

int Graph_for_Primo::count_vertex() const {
    return (int)vertices.size();
}

int Graph_for_Primo::count_edge() const {
    int count = 0;

    for (int i = 0; i < (int) vertices.size(); ++i) {
        for (const auto& e : vertices[i].adj) {
            if ((i+1) < e.to)
                ++count;
        }
    }

    return count;
}


void Graph_for_Primo::print_vertexs() const {
    std::cout << "||| Всего вершин: " << count_vertex() << "|||" << std::endl;
    for (const auto& i : vertices) {
        i.to_stream(std::cout);
    }
}


long long Graph_for_Primo::total_weight() const {
    long long count = 0;

    for (int i = 0; i < (int)vertices.size(); ++i) {
        for (const auto& u : vertices[i].adj) {
            if ((i + 1) < u.to)
                count += u.weight;
        }
    }

    return count;
}