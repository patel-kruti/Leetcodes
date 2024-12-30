// Problem - 5. Longest Palindromic Substring
// Link - https://leetcode.com/problems/longest-palindromic-substring/description/
// Topics - String, DP, Two Pointers  
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution -
// Two Pointers
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        auto expandFromCenter = [&](int left, int right){
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--;
                right++;
            }
            return make_pair(left + 1, right - 1);
        };

        for(int i = 0; i < s.size(); i++){
            auto [l1, r1] = expandFromCenter(i, i); // Odd Length Palindrome
            auto [l2, r2] = expandFromCenter(i, i + 1); // Even Length Palindrome 

            if(r1 - l1 > end - start){
                start = l1;
                end = r1;
            }
            if(r2 - l2 > end - start){
                start = l2;
                end = r2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// Dynamic Programming
