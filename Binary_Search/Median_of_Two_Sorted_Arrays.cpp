// LeetCode: Median of Two Sorted Arrays
// Difficulty: Hard
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Partition
// Time Complexity: O(log(min(m, n)))
// Auxiliary Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while(low <= high) {

            // Partition nums1
            int partition1 = low + (high-low)/2;

            // Choose partition2 so that the left half
            // contains half of the total elements
            int partition2 = (m+n+1)/2 - partition1;

            // Elements just before and after the partitions
            // INT_MIN / INT_MAX handle boundary cases
            int left1 = (partition1 == 0) ? INT_MIN : nums1[partition1-1];
            int right1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int left2 = (partition2 == 0) ? INT_MIN : nums2[partition2-1];
            int right2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Partition1 is too far right
            if(left1 > right2) {
                high = partition1 - 1;
            }

            // Partition1 is too far left
            else if(left2 > right1) {
                low = partition1 + 1;
            }

            // Correct partition found
            else {
                // Odd total length
                if((m+n)%2 == 1)
                    return max(left1, left2);

                // Even total length
                return (max(left1,left2) + min(right1,right2)) / 2.0;
            }
        }

        return 0.0;
    }
};
