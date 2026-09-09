// LeetCode: Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Answer
// Time Complexity: O(n log D)
// Auxiliary Space: O(1)

class Solution {
public:
    int possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;  //count for consecutive flowers
        int bouquets = 0; //count for bouquets
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=day) { 
                cnt++;
            if(cnt==k) {
                bouquets++;
                cnt= 0; //Reset count to zero for next consecutive flowers 
            }
            }
            else {
                cnt=0; //reset count to zero if consecutive flowers not found
            }
        }
        return bouquets >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       long long total  = 1LL*m*k;
       if(total > bloomDay.size()) return -1;
       int low = *min_element(bloomDay.begin(),bloomDay.end());
       int high = *max_element(bloomDay.begin(),bloomDay.end());
       int result = -1;
       while(low<=high) {
        int mid = low + (high-low)/2;
        if(possible(bloomDay,mid,m,k)) {
                result = mid;
                high = mid-1;
             }
            else {
                low = mid + 1;
            }
        } 
       return result;
    }
};
