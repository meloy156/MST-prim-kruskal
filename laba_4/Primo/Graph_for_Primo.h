#pragma once

#include <iostream>
#include <vector>


// ребро в списке  смежности
struct AdjEdge
{
    int to;
    int weight;

    AdjEdge(int to, int weight): to(to), weight(weight) {}
};


class Vertex {
public:
    int id;
    std::vector<AdjEdge> adj;


    explicit Vertex(int id): id(id) {}
    
    
    void add_edge(const AdjEdge& adjEdge);
    void add_edge(int to, int weight);

    void to_stream(std::ostream& os) const;
};


class Graph_for_Primo {
private:
    std::vector<Vertex> vertices;

public:
    explicit Graph_for_Primo(int n);

    void add_edge(int to_vertex, int end_vertex, int weight);

    const std::vector<AdjEdge>& neighbors(int id) const;

    int count_vertex() const;

    int count_edge() const;

    void print_vertexs() const;

    long long total_weight() const;
};