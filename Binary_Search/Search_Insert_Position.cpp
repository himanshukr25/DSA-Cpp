// LeetCode: Search Insert Position
// Difficulty: Easy
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Lower Bound / Binary Search
// Time Complexity: O(log n)
// Auxiliary Space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

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
};
