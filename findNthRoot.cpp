#include <bits/stdc++.h>
using namespace std;
long long power(int base, int exp, int limit) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
        if (res > limit) return res;
    }
    return res;
}
int findNthRoot(int m, int n) {
    if (m == 1) return 1;
    int l = 1, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long midPow = power(mid, n, m);
        if (midPow == m) return mid;
        else if (midPow > m) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int main() {
    int n = 3, m = 27;
    cout << findNthRoot(m, n) << endl;
}