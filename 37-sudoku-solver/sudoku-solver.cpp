class Solution {
    bool helper (vector<vector<char>>& v) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (v[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++) {
                    bool f = false;
                    for (int p = 0; p < 9; p++) {
                        if (v[p][j] == k) {
                            f = true;
                            break;
                        }
                    }
                    for (int p = 0; p < 9; p++) {
                        if (v[i][p] == k) {
                            f = true;
                            break;
                        }
                    }
                    int u = (i / 3) * 3, w = (j / 3) * 3;
                    for (int x = u; x < u + 3; x++) {
                        for (int y = w; y < w + 3; y++) {
                            if (v[x][y] == k) {
                                f = true;
                                break;
                            }
                        }
                        if (f) break;
                    }
                    if (!f) {
                        v[i][j] = k;
                        if (helper(v)) return true;
                        else v[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};