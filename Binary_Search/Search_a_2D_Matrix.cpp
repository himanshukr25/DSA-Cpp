// LeetCode: Search a 2D Matrix
// Difficulty: Medium
// Topic: Binary Search
// Solution: Optimal
// Algorithm: Binary Search on Flattened Matrix
// Time Complexity: O(log(m*n))
// Auxiliary Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Treat the matrix as a sorted 1D array
        int low = 0;
        int high = rows*cols - 1;

        while(low<=high) {
            int mid = low + (high-low)/2;

            // Convert 1D index to 2D coordinates
            int value = matrix[mid/cols][mid%cols];

            if(value==target)
                return true;
            else if(value<target)
                low=mid+1;
            else
                high = mid - 1;
        }

        return false;
    }
};
