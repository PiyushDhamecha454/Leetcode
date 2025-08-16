class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> newRows;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) row[j] = newRows[j - 1] + newRows[j];
            result.push_back(row);
            newRows = row;
        }
        return result;
    }
};