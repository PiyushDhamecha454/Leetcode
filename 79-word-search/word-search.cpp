class Solution {
public:
bool helper(vector<vector<char>>& board, string word, int i, int j, int index, int m, int n) {
    
    if (i < 0 || j < 0 || i == m || j == n || board[i][j] != word[index] || board[i][j] == '\0') return false;
    index++;
if (index == word.size()) return true;
    board[i][j] = 0;

    bool found = helper(board, word, i - 1, j, index, m, n) ||
                 helper(board, word, i + 1, j, index, m, n) ||
                 helper(board, word, i, j - 1, index, m, n) ||
                 helper(board, word, i, j + 1, index, m, n);

    board[i][j] = word[index - 1];
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    int index = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (board[i][j] == word[index]) if (helper(board, word, i, j, index, m, n)) return true;
    return false;
}
};