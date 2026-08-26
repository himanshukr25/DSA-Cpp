// LeetCode: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Topic: Array
// Algorithm: One-pass / Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;

        for (int i = 0; i < prices.size(); i++) {
            // Keep track of the minimum buying price
            if (prices[i] < buy) {
                buy = prices[i];
            }

            // Calculate today's profit
            int profit = prices[i] - buy;

            // Keep track of maximum profit
            if (profit > sell) {
                sell = profit;
            }
        }

        return sell;
    }
};
