// LeetCode: Majority Element
// Difficulty: Easy
// Topic: Array
// Algorithm: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int cnt=0;
         int element=0;
         for(int i=0;i<nums.size();i++) {
            if(cnt==0) {
                cnt=1;
                element=nums[i];
            }
            else if(nums[i]==element){
                cnt++;
            }
            else {
                cnt--;
            }
         }
         int cnt1=0;
         for(int i=0;i<nums.size();i++) {
            if(nums[i]==element) cnt1++;
         }
         if(cnt1>nums.size()/2) {
            return element;
         }
       return -1; 
    }
};
