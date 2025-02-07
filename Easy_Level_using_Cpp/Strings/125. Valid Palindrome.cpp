// Problem - 125. Valid Palindrome
// Link - https://leetcode.com/problems/valid-palindrome/
// Difficulty - Easy
// Tags - Strings, Two Pointers
// Approach - Two Pointers
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution:-
class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = "";
        int strLen = s.length();

        for(int i = 0; i < strLen; i++){
            if(isalpha(s[i])){
                cleanString += tolower(s[i]);
            } else if(isdigit(s[i])){
                cleanString += s[i];
            }
        }

        strLen = cleanString.length();
        for(int i = 0; i < strLen/2; i++){
            if(cleanString[i] != cleanString[strLen - i - 1]){
                return false;
            }
        } 

        return true;       
    }
};