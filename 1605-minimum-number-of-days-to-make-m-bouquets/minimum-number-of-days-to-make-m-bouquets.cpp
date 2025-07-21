class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int c = 0;
        int p = 0;
        for (int x : bloomDay) {
            if (x <= day) c++;
            else {
                p += (c / k);
                c = 0;
            }
        }
        p += c / k;
        return p >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * 1LL * k * 1LL) return -1;
        int m1 = INT_MAX, m2 = INT_MIN;
        for (int x : bloomDay) {
            m1 = min(m1, x);
            m2 = max(m2, x);
        }
        int l = m1, r = m2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(bloomDay, mid, m, k)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};