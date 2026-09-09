// LeetCode: Koko Eating Bananas
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Answer
// Time Complexity: O(n log m)
// Auxiliary Space: O(1)

class Solution {
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++) {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    
    long long calTotalHours(vector<int>&piles,int hourly) {
        long long totalH = 0 ;
        for(int i=0;i<piles.size();i++) {
            totalH += ((long long)piles[i] + hourly - 1) / hourly;
         }  
         return totalH; 
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int low = 1;
        int high = findMax(piles);

        while(low <= high) {

            int mid = low+(high-low)/ 2;

            long long totalH = calTotalHours(piles, mid);

            if(totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
