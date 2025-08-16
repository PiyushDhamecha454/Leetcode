class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int neededDays = 1;
            int currentLoad = 0;
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    neededDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }
            if (neededDays <= days) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};