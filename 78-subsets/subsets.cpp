class Solution {
public:
    vector<vector<int>> targetSumSubsequencesHelper (int i, vector<int>& v, int n, vector<int>& t) {
    if (i == n) return {t};
    t.push_back(v[i]);
    vector<vector<int>> include = targetSumSubsequencesHelper(i + 1, v, n, t);
    t.pop_back();
    vector<vector<int>> exclude = targetSumSubsequencesHelper(i + 1, v, n, t);
    include.insert(include.end(), exclude.begin(), exclude.end());
    return include;
}
vector<vector<int>> subsets(vector<int>& v) {
    vector<int> t = {};
    return targetSumSubsequencesHelper (0, v, v.size(), t);
}
};