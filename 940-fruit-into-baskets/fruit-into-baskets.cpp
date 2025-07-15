class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0, mL = 0, n = fruits.size();
        for (int r = 0; r < n; r++) {
            mp[fruits[r]]++;
            if (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            mL = max(mL, r - l + 1);
        }
        return mL;
    }
};