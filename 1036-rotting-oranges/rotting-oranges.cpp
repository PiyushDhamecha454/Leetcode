class Solution {
public:
int orangesRotting(vector<vector<int>>& v) {
    if (v.empty()) return 0;
    queue<pair<int, int>> q;
    int n = v.size(), m = v[0].size();
    int totalOranges = 0, count = 0, totalTime = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != 0) totalOranges++;
            if (v[i][j] == 2) q.push({i, j});
        }
    }
    int dX[4] = {0, 0, 1, -1};
    int dY[4] = {1, -1, 0, 0};
    while (!q.empty()) {
        int k = q.size();
        count += k;
        while (k--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nX = x + dX[i], nY = y + dY[i];
                if ((nX >= 0) && (nX < n) && (nY >= 0) && (nY < m) && v[nX][nY] == 1) {
                    v[nX][nY] = 2;
                    q.push({nX, nY});
                }
            } 
        }
        if (!q.empty()) totalTime++;
    }
    return totalOranges == count ? totalTime : -1;
}
};