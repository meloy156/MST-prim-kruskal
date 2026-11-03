#pragma once


#include <vector>
#include <numeric>


class DSU {
private:
    std::vector<int> parent;

    std::vector<int> rank_;


public:
    explicit DSU(int n);

    // найти корень компоненты
    int find(int x);

    // объединить 2 компоненты связанности
    bool unite(int a, int b);
};