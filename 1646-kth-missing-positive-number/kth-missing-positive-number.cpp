class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0, current = 1, i = 0;
        while (missing < k) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                missing++;
                if (missing == k) return current;
            }
            current++;
        }
        return -1; // Should never reach here
    }
};
