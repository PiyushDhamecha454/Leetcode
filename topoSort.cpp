#include <bits/stdc++.h>
using namespace std;
// Depth-First-Search way for Topologic Sort
void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adjList) {
    visited[node] = true;
    for (auto v : adjList[node]) if (!visited[v]) dfs(v, visited, st, adjList);
    st.push(node);
}
vector<int> topoSort (vector<vector<int>>& edges, int x) {
    vector<vector<int>> adjList(x + 1);
    vector<bool> visited(x + 1);
    vector<int> res;
    for (auto e : edges) adjList[e[0]].push_back(e[1]);
    stack<int> st;
    for (int i = 0; i < x + 1; i++) if (!visited[i]) dfs(i, visited, st, adjList);
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
void printVector (const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << endl;
}
int main() {
  vector<vector<int>> edges = {{5, 0}, {4, 0}, {5, 2}, {4, 1}, {2, 3}, {3, 1}};
  int x = INT_MIN;
  for (auto e : edges) x = max(x, max(e[1], e[0]));
  printVector(topoSort(edges, x));
}