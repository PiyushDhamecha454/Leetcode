class Solution {
    bool dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList, vector<bool>& onPath) {
        visited[node] = true;
        onPath[node] = true;
        for (int nei: adjList[node]) {
            if (!visited[nei]) {
                if (dfs(nei, visited, adjList, onPath)) return true;
            }
            else if (onPath[nei]) return true;
        }
        onPath[node] = false;
        return false;
    }
public:
    bool canFinish(int x, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(x + 1);
        for (auto e : edges) adjList[e[1]].push_back(e[0]);
        vector<bool> visited(x + 1, false);
        vector<bool> onPath(x + 1, false);
        for (int i = 0; i < x + 1; i++) if (!visited[i]) if (dfs(i, visited, adjList, onPath)) return false;
        return true;
    }
};