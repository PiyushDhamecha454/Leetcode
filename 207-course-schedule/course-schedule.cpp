class Solution {
public:
    bool canFinish(int x, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(x + 1);
        vector<int> indegree(x + 1, 0);
        int c = 0;
        queue<int> q;
        for (auto e : edges) {
            adjList[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        for (int i = 0; i <= x; i++) if (!indegree[i]) q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            c++;
            for (int nei: adjList[node]) {
                indegree[nei]--;
                if (!indegree[nei]) q.push(nei);
            }
        }
        return c == x + 1;
    }
};