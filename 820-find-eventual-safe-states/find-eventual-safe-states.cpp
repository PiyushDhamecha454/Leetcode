class Solution {
    enum State {UNVISITED = 0, VISITING, SAFE};
    bool dfs(int node, vector<vector<int>>& graph, vector<State>& visited) {
        if (visited[node] == VISITING) return false;
        if (visited[node] == SAFE) return true;
        visited[node] = VISITING;
        for (int nei : graph[node]) if (!dfs(nei, graph, visited)) return false;
        visited[node] = SAFE;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int x = graph.size();
        vector<State> visited(x, UNVISITED);
        for (int i = 0; i < x; i++) {
            if (dfs(i, graph, visited)) res.push_back(i);
        }
        return res;
    }
};