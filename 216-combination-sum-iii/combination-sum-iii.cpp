class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>>& result, int k, vector<int>& temp) {
    if (target == 0 && temp.size() == k) {
        result.push_back(temp);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i], i + 1, result, k, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates(9);
    for (int i = 0; i < 9; i++) candidates[i] = i + 1;
    vector<vector<int>> result;
    vector<int> temp;
    helper(candidates, n, 0, result, k, temp);
    return result;
}
};