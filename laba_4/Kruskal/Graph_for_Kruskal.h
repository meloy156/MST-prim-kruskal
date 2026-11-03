#pragma once

#include <iostream>
#include <vector>


struct Edge
{
    int to_vertex, end_vertex, weight;

    Edge(int to_vertex, int end_vertex, int weight)
      : to_vertex(to_vertex)
      , end_vertex(end_vertex)
      , weight(weight)
    {}

    bool operator<(const Edge& other) const;

    void to_stream(std::ostream& os) const;
};



class Graph_for_Kruskal {
private:
    int count_vertex;
    std::vector<Edge> edges;

public:
    explicit Graph_for_Kruskal(int count_vertex);

    void add_edge(int to_vertex, int end_vertex, int weight);

    int return_count_vertex() const;
    int return_count_edge() const;
    long long total_weight() const;

    const std::vector<Edge>& get_edges() const;
    void print_edges() const;

};
