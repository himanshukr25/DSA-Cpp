// LeetCode: Reverse Words in a String
// Difficulty: Medium
// Topic: Strings
// Solution: Optimal
// Algorithm: String Stream + Reversal
// Time Complexity: O(n)
// Auxiliary Space: O(n)

class Solution {
public:
    string reverseWords(string s) {

        // Extract words while automatically ignoring extra spaces
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        string ans;

        // Construct the result with a single space between words
        for(int i=0; i<words.size(); i++) {
            if(i > 0)
                ans += " ";

            ans += words[i];
        }

        return ans;
    }
};
