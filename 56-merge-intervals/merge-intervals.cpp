class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort (intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] < b[1]);
            }
        );
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& next = intervals[i];
            if (next[0] <= curr[1]) curr[1] = max(curr[1], next[1]);
            else {
                res.push_back(curr);
                curr = next;
            }
        }
        res.push_back(curr);
        return res;
    }
};