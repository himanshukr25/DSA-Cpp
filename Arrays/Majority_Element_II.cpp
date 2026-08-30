// LeetCode: Majority Element II
// Difficulty: Medium
// Topic: Array
// Solution: Optimal
// Algorithm: Extended Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Auxiliary Space: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Find two potential candidates
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && el2 != nums[i]) {
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && el1 != nums[i]) {
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                count1++;
            }
            else if (nums[i] == el2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Verify the candidates
        vector<int> ans;
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                count1++;

            if (nums[i] == el2)
                count2++;
        }

        int minCount = nums.size() / 3 + 1;

        if (count1 >= minCount)
            ans.push_back(el1);

        if (count2 >= minCount)
            ans.push_back(el2);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
