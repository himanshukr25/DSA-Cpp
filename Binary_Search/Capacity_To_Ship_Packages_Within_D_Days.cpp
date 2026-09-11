// LeetCode: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Answer
// Time Complexity: O(n log S)
// Auxiliary Space: O(1)

class Solution {
public:
    int possible(vector<int>& weights, int capacity, int days) {
        int currentweight=0;
        int daysNeeded=1;
        for(int i=0;i<weights.size();i++) {
            if(currentweight+weights[i]<=capacity) {
                currentweight += weights[i];
            }
            else{
                daysNeeded++;
                currentweight = weights[i];
            }
        }
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0LL);
        int result=high;

        while(low<=high) {
            int mid=low+(high-low)/2;

            if(possible(weights,mid,days)) {
                result = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return result;
    }
};
