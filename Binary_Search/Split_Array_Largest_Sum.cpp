// LeetCode: Split Array Largest Sum
// Difficulty: Hard
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Answer
// Time Complexity: O(n log S), where S = sum of all elements
// Auxiliary Space: O(1)

class Solution {
public:
    // Checks if the array can be split into at most k subarrays
    // such that each subarray has sum <= maxSum
    int largestSubArray(vector<int>& nums, int maxSum, int k) {
        int sum = 0;
        int count = 1;  // At least one subarray is required

        for(int i=0;i<nums.size();i++) {
            if(sum+nums[i]<=maxSum) {
                sum += nums[i];
            }
            else {
                // Start a new subarray
                count++;
                sum = nums[i];
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // Minimum possible answer: largest element
        int low = *max_element(nums.begin(),nums.end());

        // Maximum possible answer: sum of all elements
        int high = accumulate(nums.begin(),nums.end(),0LL);

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(largestSubArray(nums,mid,k)) {
                // mid is possible, try to find a smaller answer
                high = mid-1;
            }
            else{
                // mid is not possible, increase the maximum allowed sum
                low = mid+1;
            }
        }

        return low;
    }
};
