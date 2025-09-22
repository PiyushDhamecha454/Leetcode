class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int c = 0, i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                c++;
                i++;
                j--;
            }
            else if (sum > k) j--;
            else i++;
        }
        return c;
    }
};