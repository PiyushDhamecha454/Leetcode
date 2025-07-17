class Solution {
public:
    int subarraysTillKDistinct(vector<int>& nums, int k) {
        int l = 0, c = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            c += r - l + 1;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysTillKDistinct(nums, k) - subarraysTillKDistinct(nums, k - 1);
    }
};