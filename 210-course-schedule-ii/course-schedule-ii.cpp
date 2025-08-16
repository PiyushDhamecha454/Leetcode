class Solution {
    bool dfs(int c, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& res) {
        visited[c] = 1;
        for (int n : adjList[c]) {
            if (visited[n] == 0) {
                if (!dfs(n, adjList, visited, res)) return false;
            }
            else if (visited[n] == 1) return false;
        }
        visited[c] = 2;
        res.push_back(c);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> res;

        for (vector<int> v : prerequisites) adjList[v[1]].push_back(v[0]);

        for (int c = 0; c < numCourses; c++) if (visited[c] == 0) if (!dfs(c, adjList, visited, res)) return {};

        reverse(res.begin(), res.end());

        return res;
    }
};