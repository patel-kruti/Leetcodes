// Problem: 49. Group Anagrams
// Link: https://leetcode.com/problems/group-anagrams/description/
// Time Complexity: O(n * k log k)
// Space Complexity: O(n * k)
// Topics: Array, Hash Table, String, Sorting
// Solution: 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for(const string&s: strs){  // sort each string element in strs array - O(n)
            string key = s;
            sort(key.begin(), key.end()); // O(k log k)
            anagrams[key].push_back(s);  // store it in dictionary. {key1: [s1, s2, s3], key2: [s4]}
        }

        for(const auto&pair: anagrams){  // extract the vector/value from the dictionary - O(n)
            result.push_back(pair.second);
        }

        return result;
    }
};