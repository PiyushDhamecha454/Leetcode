class Solution {
public:
    bool isSafe (vector<string>& temp, int i, int j, int n) {
    for (int x = 0; x < n; x++) if (temp[x][j] == 'Q') return false;
    for (int y = 0; y < n; y++) if (temp[i][y] == 'Q') return false;
    for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) if (temp[x][y] == 'Q') return false;
    for (int x = i - 1, y = j + 1; x >= 0 && y < n; x--, y++) if (temp[x][y] == 'Q') return false;
    return true;
}

void helper (vector<vector<string>>& v, vector<string>& temp, int i, int n) {
    if (i == n) {
        v.push_back(temp);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (isSafe(temp, i, j, n)) {
            temp[i][j] = 'Q';
            helper(v, temp, i + 1, n);
            temp[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens (int n) {
    vector<vector<string>> v;
    vector<string> temp(n, string(n, '.'));
    helper(v, temp, 0, n);
    return v;
}
};