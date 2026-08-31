// LeetCode: 3Sum
// Difficulty: Medium
// Topic: Array, Two Pointers, Sorting
// Solution: Optimal
// Algorithm: Sorting + Two Pointers
// Time Complexity: O(n log n + n^2)
// Auxiliary Space: O(1)
// Output Space: O(k), where k = number of unique triplets

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total < 0) {
                    j++;
                }
                else if (total > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};
