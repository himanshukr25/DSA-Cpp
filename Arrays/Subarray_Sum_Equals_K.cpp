// LeetCode: Subarray Sum Equals K
// Difficulty: Medium
// Topic: Array, Prefix Sum, Hashing
// Solution: Optimal
// Algorithm: Prefix Sum + Hash Map
// Time Complexity: O(n log n)
// Auxiliary Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;

        int preSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            int remove = preSum - k;

            count += mpp[remove];

            mpp[preSum]++;
        }

        return count;
    }
};
