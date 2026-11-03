#include "Graph_for_Kruskal.h"


void Edge::to_stream(std::ostream& os) const {
    os  << "{" 
           << to_vertex << ", "
           << end_vertex << ", "
           << weight 
        << "}, ";
}

bool Edge::operator<(const Edge& other) const {
    return this->weight < other.weight;
}


Graph_for_Kruskal::Graph_for_Kruskal(int count_vertex)
  : count_vertex(count_vertex), edges()
  {}


void Graph_for_Kruskal::add_edge(int to_vertex, int end_vertex, int weight) {
    edges.emplace_back(to_vertex, end_vertex, weight);
}


int Graph_for_Kruskal::return_count_vertex() const {
    return count_vertex;
}

int Graph_for_Kruskal::return_count_edge() const {
    return (int)edges.size();
}


long long Graph_for_Kruskal::total_weight() const {
    long long result = 0;

    for (const Edge& e : edges) {
        result += e.weight;
    }

    return result;
}


const std::vector<Edge>& Graph_for_Kruskal::get_edges() const {
    return edges;
}


void Graph_for_Kruskal::print_edges() const {
    std::cout << "|||Всего ребер в графе: " << return_count_edge() << "|||" << std::endl;
    std::cout << "{1 вершина, 2 вершина, вес}" << std::endl;

    for (const auto& e : edges) {
        e.to_stream(std::cout);
    }

    std::cout << std::endl;
}


