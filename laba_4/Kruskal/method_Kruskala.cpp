#include "method_Kruskala.h"
#include "DSU.h"

#include <algorithm>

Graph_for_Kruskal method_kruskal(const Graph_for_Kruskal& graph) {
    int count_vertex = graph.return_count_vertex();

    // отсортированный вектор ребер
    std::vector<Edge> edges = graph.get_edges();
    std::sort(edges.begin(), edges.end());

    DSU dsu(count_vertex + 1);
    Graph_for_Kruskal result_graph(count_vertex);


    for (const Edge& e : edges) {
        if (dsu.unite(e.to_vertex, e.end_vertex)) {
            result_graph.add_edge(e.to_vertex, e.end_vertex, e.weight);
            if (result_graph.return_count_edge() == count_vertex - 1) break;
        }
    }

    return result_graph;
}