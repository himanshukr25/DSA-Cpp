// LeetCode: Next Permutation
// Difficulty: Medium
// Topic: Array
// Algorithm: Next Permutation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no such element exists, this is the last permutation
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[ind]
        // Since the suffix is decreasing, the first one from the right works
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
