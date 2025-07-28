class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>>& result, int n, vector<int>& temp) {
    if (index == n) {
        if (target == 0) result.push_back(temp);
        return;
    }
    if (candidates[index] <= target) {
        temp.push_back(candidates[index]);
        helper(candidates, target - candidates[index], index, result, n, temp);
        temp.pop_back();        
    }
    helper(candidates, target, index + 1, result, n, temp);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    int n = candidates.size();
    helper(candidates, target, 0, result, n, temp);
    return result;
}
};