// Problem - 28. Find the Index of the First Occurrence in a String
// Link: https://leetcode.com/problems/implement-strstr/
// Topics: Strings, Two Pointers, String Matching
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution :-
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int needleLen = needle.length();
        int i = 0; 
        while(i < haystack.length()){
            if(needle[0] == haystack[i]){
                index = i;
                for(int j = 0; j < needleLen; j++){
                    if(needle[j] == haystack[i]){
                        if(j == needleLen - 1){
                            return index;
                        }
                        i++;
                    } else {
                        i = index;
                        index = -1;
                        break;
                    }
                }
            }
            i++;
        }

        return index;
    }
};