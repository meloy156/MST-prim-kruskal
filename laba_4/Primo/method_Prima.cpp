#include "method_Prima.h"
#include <climits>
#include <vector>

Graph_for_Primo method_Prima(const Graph_for_Primo& graph) {
    
    // колво вершин в исходном
    int count_vertex = graph.count_vertex();


    // массивы для алгоритм
    // i - номер вершины
    // v - значение

    // цена до вершины
    std::vector<int> key(count_vertex + 1, INT_MAX);
    
    // от какой вершины выбрали цену
    std::vector<int> parent(count_vertex + 1, -1);
    
    // включили ли вершину
    std::vector<int> inMST(count_vertex + 1, false);



    // старт с 1 вершины
    key[1] = 0;



    for (int i = 1; i <= count_vertex; ++i) {

        // ищем мин ребро вершины которая не вкл еще 
        int min = INT_MAX;
        int index_min = INT_MAX;
        for (int j = 1; j <= count_vertex; ++j) {
            if (!inMST[j] && key[j] < min) {
                min       = key[j];
                index_min = j;
            }
        }

        if (index_min == -1 || min == INT_MAX) break;

        // добавляем в дерево эту вершину
        inMST[index_min] = true;


        // добавляем ребра новой вершины
        for (const AdjEdge& a : graph.neighbors(index_min)) {
            if (!inMST[a.to] && a.weight < key[a.to]) {
                key[a.to]    = a.weight;
                parent[a.to] = index_min;
            }
        }
    }



    // сборка итогового графа
    Graph_for_Primo result(count_vertex);
    for (int v = 1; v <= count_vertex; ++v) {
        if (parent[v] != -1) {
            result.add_edge(parent[v], v, key[v]);
        }
    }

    return result;
}