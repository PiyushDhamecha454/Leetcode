class Solution {
public:
    int sumTillNice(vector<int>& nums, int k) {
        int l = 0, c = 0, t = 0;
        for (int r = 0; r < nums.size(); r++) {
            t += (nums[r] % 2);
            while (t > k) {
                t -= (nums[l] % 2);
                l++;
            }
            c += r - l + 1;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sumTillNice(nums, k) - sumTillNice(nums, k - 1);
    }
};