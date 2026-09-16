// LeetCode: Largest Odd Number in String
// Difficulty: Easy
// Topic: Strings
// Solution: Optimal
// Algorithm: Right-to-Left Traversal
// Time Complexity: O(n)
// Auxiliary Space: O(n) due to returned substring

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1; i>=0; i--) {
            if((num[i]-'0') % 2 == 1) {
                return num.substr(0, i+1);
            }
        }

        return "";
    }
};
