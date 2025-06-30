class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;

        int mL = 0;
        for (auto& p: mp) {
            if (mp.count(p.first + 1)) {
                int curr = p.second + mp[p.first + 1];
                mL = max(mL, curr);
            }
        }

        return mL;
    }
};