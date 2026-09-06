// LeetCode: Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Lower Bound + Upper Bound
// Time Complexity: O(log n)
// Auxiliary Space: O(1)

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);

        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};

        return {lb, upperBound(nums, target) - 1};
    }
};
