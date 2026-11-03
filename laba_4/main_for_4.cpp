#include "Primo/Graph_for_Primo.h"
#include "Primo/method_Prima.h"
#include "Kruskal/Graph_for_Kruskal.h"
#include "Kruskal/method_Kruskala.h"

#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    // исходный граф
    const int count_vertex = 8;
    const int edges[12][3] = {
        {1, 2, 2}, {1, 5, 3}, {1, 6, 10},
        {2, 3, 1}, {2, 7, 35},
        {3, 4, 17},
        {4, 7, 13},
        {5, 6, 11}, {5, 8, 20},
        {6, 7, 15}, {6, 8, 12},
        {7, 8, 10}
    };


    
    // ||| ПРИМО |||
    Graph_for_Primo graph_primo(count_vertex);
    for (auto& e : edges) {
        graph_primo.add_edge(e[0], e[1], e[2]);
    }
    
    Graph_for_Primo result_Primo = method_Prima(graph_primo);
    result_Primo.print_vertexs();
    
    
    // ||| Крускала |||
    Graph_for_Kruskal graph_kruskal(count_vertex);
    for (auto& e : edges) {
        graph_kruskal.add_edge(e[0], e[1], e[2]);
    }

    Graph_for_Kruskal result_Kruskal = method_kruskal(graph_kruskal);
    result_Kruskal.print_edges();





    // ||| Проверка и сравнение |||
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "||| Сравнение итогового веса |||" << std::endl;
    std::cout << "Примо: " << result_Primo.total_weight() << std::endl;
    std::cout << "Крускаль: " << result_Kruskal.total_weight() << std::endl;
}