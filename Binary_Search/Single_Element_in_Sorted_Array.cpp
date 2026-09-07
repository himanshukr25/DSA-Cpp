// LeetCode: Single Element in a Sorted Array
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Modified Binary Search
// Time Complexity: O(log n)
// Auxiliary Space: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even so that mid and mid+1 form a pair
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Pair is intact, so single element is to the right
                low = mid + 2;
            } else {
                // Pair is broken, so single element is at or to the left
                high = mid;
            }
        }

        return nums[low];
    }
};
