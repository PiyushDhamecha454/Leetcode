class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int n = v.size(), m = v[0].size();
        q.push({sr, sc});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (visited[x][y]) continue;
            if (x + 1 < n && v[x + 1][y] == v[x][y]) q.push({x + 1, y});
            if (y + 1 < m && v[x][y + 1] == v[x][y]) q.push({x, y + 1});
            if (x - 1 >= 0 && v[x - 1][y] == v[x][y]) q.push({x - 1, y});
            if (y - 1 >= 0 && v[x][y - 1] == v[x][y]) q.push({x, y - 1});
            v[x][y] = color;
            visited[x][y] = true;
        }
        return v;
    }
};