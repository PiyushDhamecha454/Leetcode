class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>>& result, int n, vector<int>& temp) {
    if (target == 0) {
        result.push_back(temp);
        return;
    }
    for (int i = index; i < n; i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        temp.push_back(candidates[i]);
        helper(candidates, target - candidates[i], i + 1, result, n, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, result, n, temp);
    return result;
}
};