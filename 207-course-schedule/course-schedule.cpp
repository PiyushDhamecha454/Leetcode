class Solution {
    bool dfs (int node, vector<bool>& visited, vector<bool>& onPath, vector<vector<int>>& adjList) {
        if (onPath[node]) return true;
        if (visited[node]) return false;
        visited[node] = true;
        onPath[node] = true;
        for (int nei : adjList[node]) if (dfs(nei, visited, onPath, adjList)) return true;
        onPath[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<int>> adjList(numCourses);
        for (auto e : p) adjList[e[1]].push_back(e[0]);
        vector<bool> visited(numCourses, false), onPath(numCourses, false);
        for (int i = 0; i < numCourses; i++) if (!visited[i] && dfs(i, visited, onPath, adjList)) return false;
        return true;
    }
};