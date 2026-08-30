// LeetCode: Pascal's Triangle
// Difficulty: Easy
// Topic: Array, Mathematics
// Solution: Optimal
// Algorithm: Binomial Coefficient
// Time Complexity: O(numRows^2)
// Auxiliary Space: O(1) excluding output

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> temp;
            long long value = 1;

            for (int j = 0; j <= i; j++) {
                temp.push_back(value);

                value = value * (i - j);
                value = value / (j + 1);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
