class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = n - 1; i >= index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }
        int s = index + 1, e = n - 1;
        while (s < e) swap(nums[s++], nums[e--]);
    }
};