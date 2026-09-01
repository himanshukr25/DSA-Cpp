// LeetCode: Merge Intervals
// Difficulty: Medium
// Topic: Array, Sorting, Greedy
// Solution: Optimal
// Algorithm: Sorting + Greedy
// Time Complexity: O(n log n)
// Auxiliary Space: O(n) for the output

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
