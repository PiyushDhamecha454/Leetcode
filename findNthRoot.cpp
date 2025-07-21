#include<bits/stdc++.h>
using namespace std;
int findNthRoot(int m, int n) {
    if (m == 1) return 1;
    int l = 1, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (pow(mid, n) == m) return mid;
        else if (pow(mid, n) > m) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int main() {
    int n = 3, m = 27;
    cout << findNthRoot(m, n) << endl;
}