class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), c = 0;
        vector<bool> visited(n + 1, false);
        vector<vector<int>> adjList(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1)
                    adjList[i].push_back(j);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                c++;
                q.push(i);
            }
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int y : adjList[x]) {
                    if (!visited[y]) {
                        visited[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        return c;
    }
};