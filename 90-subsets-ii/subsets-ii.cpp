class Solution {
public:
    void helper (vector<int>& nums, set<vector<int>>& res, int index, vector<int>& temp, int n) {
    if (index == n) {
        res.insert(temp);
        return;
    }
    temp.push_back(nums[index]);
    helper (nums, res, index + 1, temp, n);
    temp.pop_back();
    helper (nums, res, index + 1, temp, n);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> result;
    vector<int> temp;
    int n = nums.size();
    sort (nums.begin(), nums.end());
    helper(nums, result, 0, temp, n);
    vector<vector<int>> res;
    for (auto it : result) res.push_back(it);
    return res;
}
};