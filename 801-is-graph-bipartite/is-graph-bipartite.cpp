class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (int y : graph[x]) {
                        if (color[y] == -1) {
                            int nC = color[x] == 0 ? 1 : 0;
                            color[y] = nC;
                            q.push(y);
                        }
                        else if (color[y] == color[x]) return false;
                    }
                }
            }
        }
        return true;
    }
};