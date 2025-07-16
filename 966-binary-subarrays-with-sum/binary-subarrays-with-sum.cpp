class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subArraySumAtMost(nums, goal) - subArraySumAtMost (nums, goal - 1);
    }
    int subArraySumAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, c = 0, t = 0;
        for (int r = 0; r < nums.size(); r++) {
            t += nums[r];
            while (t > goal) {
                t -= nums[l];
                l++;
            }
            c += r - l + 1;
        }
        return c;
    }
};