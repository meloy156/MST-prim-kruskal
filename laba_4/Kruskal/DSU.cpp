#include "DSU.h"


DSU::DSU(int n)
  : parent(n), rank_(n, 0)
{
    std::iota(parent.begin(), parent.end(), 0);
}


int DSU::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool DSU::unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    if (rank_[a] < rank_[b]) std::swap(a, b);

    parent[b] = a;
    if (rank_[a] == rank_[b]) ++rank_[a];

    return true;
}