// Problem - 344. Reverse String
// Link - https://leetcode.com/problems/reverse-string/
// Difficulty - Easy
// Tags - Strings, Two Pointers
// Approach - Two Pointers
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution:-
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};