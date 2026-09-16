// LeetCode: Search a 2D Matrix II
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Each Row
// Time Complexity: O(m log n)
// Auxiliary Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Perform binary search on each row
        for(int i=0;i<m;i++) {
            int low = 0, high = n-1;

            while(low<=high) {
                int mid = low+(high-low)/2;

                if(matrix[i][mid]==target)
                    return true;

                else if(matrix[i][mid]<target)
                    low = mid+1;

                else
                    high = mid-1;
            }
        }

        return false;
    }
};
