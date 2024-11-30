// Problem - 125. Valid Palindrome
// Topics: Two Pointers, String
// Link - https://leetcode.com/problems/valid-palindrome/description/
// Runtime 0ms Beats 100.00% Analyze Complexity Memory 10.27 MB Beats 5.38%
// Time Complexity: O(n)
// Space Complexity: O(m)
// Solution : 
class Solution {
public:
    bool isPalindrome(string s) {
        string filteredString;

        for(char c: s){
            if(isalnum(c)){
                filteredString += tolower(c);
            }
        }

        int left = 0, right = filteredString.size() - 1;
        while(left < right){
            if(filteredString[left] != filteredString[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};