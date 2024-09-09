#include <iostream>
#include <vector>
#include <cassert>

class UnionFind {
public:
    UnionFind(int n) {
        parents.resize(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }
    
    int find_parent(int u) {
        if (parents[u] != u) {
            parents[u] = find_parent(parents[u]);
        }
        return parents[u];
    }
    
    void unite(int u, int v) {
        int pu = find_parent(u);
        int pv = find_parent(v);
        if (pu != pv) {
            parents[pu] = pv;
        }
    }
    
private:
    std::vector<int> parents;
};

int main() {
    UnionFind union_find(10);
    union_find.unite(1, 2);
    union_find.unite(1, 3);
    union_find.unite(2, 4);

    assert(union_find.find_parent(3) == union_find.find_parent(4));

    return 0;
}