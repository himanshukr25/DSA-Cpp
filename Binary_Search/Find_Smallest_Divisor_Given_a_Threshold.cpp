// LeetCode: Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Answer
// Time Complexity: O(n log M)
// Auxiliary Space: O(1)

class Solution {
public:
    long long smallestdiv(vector<int>& nums, int divisor,  int threshold) {
       
        long long smalldiv = 0;
        for(int i= 0;i<nums.size();i++) {
           
                smalldiv += ceil((double) nums[i]/ divisor);
                    
                }
            return smalldiv<=threshold;    
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result = -1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(smallestdiv(nums,mid,threshold)) {
                    result=mid;
                    high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return result;
    }
};
