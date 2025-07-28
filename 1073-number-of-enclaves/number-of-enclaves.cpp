class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        vector<int> dX = {0, 0, -1, 1}, dY = {-1, 1, 0, 0};
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 2;
            }
            if (grid[i][m - 1] == 1) {
                q.push({i, m - 1});
                grid[i][m - 1] = 2;
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                q.push({0, i});
                grid[0][i] = 2;
            }
            if (grid[n - 1][i] == 1) {
                q.push({n - 1, i});
                grid[n - 1][i] = 2;
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nX = x + dX[i], nY = y + dY[i];
                if (nX >= 0 && nY >= 0 && nX < n && nY < m && (grid[nX][nY] == 1)) {
                    q.push({nX, nY});
                    grid[nX][nY] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
                else if (grid[i][j] == 2) grid[i][j] = 1;
            }
        }
        return count;
    }
};