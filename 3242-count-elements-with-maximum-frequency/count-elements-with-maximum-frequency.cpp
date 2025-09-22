class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mF = INT_MIN, c = 0;
        for (int n : nums) mp[n]++;
        for (auto& p : mp) mF = max(mF, p.second);
        for (auto& p : mp) c += (p.second == mF);
        return c * mF;
    }
};