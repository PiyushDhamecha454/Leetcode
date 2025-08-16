class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = INT_MIN, n = piles.size();
        for (int i = 0; i < n; i++) m = max(m, piles[i]);
        int l = 1, r = m;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long c = 0;
            for (int i = 0; i < n; i++) c += (long long) (piles[i] + mid - 1) / mid;
            if (c <= h) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};