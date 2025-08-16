#include <bits/stdc++.h>
using namespace std;
// Breadth-First-Search way for Topologic Sort
vector<int> kahnsAlgo (vector<vector<int>>& edges, int x) {
    vector<vector<int>> adjList(x + 1);
    vector<int> indegree(x + 1, 0);
    vector<int> topoSort;
    for (auto e : edges) {
        adjList[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    queue<int> q;
    for (int i = 0; i <= x; i++) if (indegree[i] == 0) q.push(i);
    while (!q.empty()) {
        int node = q.front();
        topoSort.push_back(node);
        q.pop();
        for (int nei : adjList[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) q.push(nei);
        }
    }
    return topoSort;
}
void printVector (const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << endl;
}
int main() {
  vector<vector<int>> edges = {{5, 0}, {4, 0}, {5, 2}, {4, 1}, {2, 3}, {3, 1}};
  int x = INT_MIN;
  for (auto e : edges) x = max(x, max(e[1], e[0]));
  printVector(kahnsAlgo(edges, x));
}