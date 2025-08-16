class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, c = 0, mC = INT_MIN;
        map<int, int> mp;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            c += nums[r];
            while (mp[nums[r]] > 1) {
                c -= nums[l];
                mp[nums[l]]--;
                l++;
            }
            mC = max(mC, c);
        }
        return mC;
    }
};