class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), l = 1, r = *max_element(nums.begin(), nums.end());;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long x = 0;
            for (int y : nums) x += ((y + mid - 1) / mid);
            if (x <= threshold) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};