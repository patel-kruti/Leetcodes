// Problem: 217. Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/description/
// Time Complexity: O(n)
// Space Complexity: O(n)
// Topics: Array, Hash Table, Sorting
// Solution:
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return false;
        }
        unordered_set<int> seen; // Created Hash set

        for(int num: nums){      // Iterating through array
            if (seen.count(num)){  // Number already existing in hash?
                return true;    // Duplicate Found
            }
            seen.insert(num);   // insert the element in hash
        }

        return false; // All unique
    }
};