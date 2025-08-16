class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int nodes = 1; nodes <= n; ++nodes) {
            for (int i = 1; i <= nodes; i++) {
                int left = i - 1;
                int right = nodes - i;
                dp[nodes] += dp[left] * dp[right];
            }
        }

        return dp[n];
    }
};