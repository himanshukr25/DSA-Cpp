// LeetCode: 4Sum
// Difficulty: Medium
// Topic: Array, Two Pointers, Sorting
// Solution: Optimal
// Algorithm: Sorting + Two Pointers
// Time Complexity: O(n^3)
// Auxiliary Space: O(1)
// Output Space: O(k), where k = number of unique quadruplets

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n; a++) {
            // Skip duplicate first elements
            if (a > 0 && nums[a] == nums[a - 1])
                continue;

            for (int b = a + 1; b < n; b++) {
                // Skip duplicate second elements
                if (b != a + 1 && nums[b] == nums[b - 1])
                    continue;

                int c = b + 1;
                int d = n - 1;

                while (c < d) {
                    long long sum = nums[a];
                    sum += nums[b];
                    sum += nums[c];
                    sum += nums[d];

                    if (sum == target) {
                        ans.push_back({
                            nums[a],
                            nums[b],
                            nums[c],
                            nums[d]
                        });

                        c++;
                        d--;

                        // Skip duplicates
                        while (c < d && nums[c] == nums[c - 1])
                            c++;

                        while (c < d && nums[d] == nums[d + 1])
                            d--;
                    }
                    else if (sum < target) {
                        c++;
                    }
                    else {
                        d--;
                    }
                }
            }
        }

        return ans;
    }
};
