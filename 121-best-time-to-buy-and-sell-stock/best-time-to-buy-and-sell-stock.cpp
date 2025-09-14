class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimumCost = INT_MAX, maxProfit = INT_MIN;
        for (int i = 0; i < n; i++) {
            minimumCost = min(minimumCost, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minimumCost);
        }
        return maxProfit;
    }
};