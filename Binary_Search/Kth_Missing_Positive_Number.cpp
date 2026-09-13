// LeetCode: Kth Missing Positive Number
// Difficulty: Easy
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Missing Count
// Time Complexity: O(log n)
// Auxiliary Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int low=0, high=arr.size()-1;
      while(low<=high) {
        int mid = low+(high-low)/2;
        if(arr[mid]-(mid+1)<k) {
            low=mid+1;
        }
        else{
            high = mid-1;
        }
      }
      return (low+k);
    }
};
