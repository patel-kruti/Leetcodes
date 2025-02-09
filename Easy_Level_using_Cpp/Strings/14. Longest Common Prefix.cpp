// Problem - 14. Longest Common Prefix
// Link - https://leetcode.com/problems/longest-common-prefix/
// Difficulty - Easy
// Tags - Strings, Trie
// Approach - Vertical Scanning
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution:-
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string resultStr = strs[0];

        for(int i = 1; i < strs.size(); i++){
            string currMatch = "";
            for(int j = 0; j < resultStr.length() && j < strs[i].length(); j++){
                if(resultStr[j] == strs[i][j]){
                    currMatch += resultStr[j];
                } else {
                    break;
                }
            }
            resultStr = currMatch;
        }

        return resultStr;
    }
};