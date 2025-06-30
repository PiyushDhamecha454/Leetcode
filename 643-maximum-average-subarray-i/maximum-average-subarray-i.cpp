class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), mS = INT_MIN, s = 0;
        for (int i = 0; i < k; i++) s += nums[i];
        mS = max(mS, s);
        for (int i = k; i < n; i++) {
            s += nums[i] - nums[i - k];
            mS = max(mS, s);
        }
        double t = (double)mS/((double)k);
        return t;
    }
};