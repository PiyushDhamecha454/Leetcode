#include <bits/stdc++.h>
using namespace std;
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;  // Initially, each node is its own parent
    }
    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) parent[py] = px;
    }
};
int main() {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(0, 4);
    cout << (uf.find(0) == uf.find(2) ? "Connected" : "Not connected") << endl;
    cout << uf.find(3) << endl;
}