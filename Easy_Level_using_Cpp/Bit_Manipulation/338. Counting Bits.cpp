/*
Problem: 338. Counting Bits
Link: https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=wv5ww91e
Topics: BitManipulation, Dynamic Programming
Level: Easy
*/

// Appraoch: Brute Force
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for(int i = 0; i <= n; i++){
            string bits = std::bitset<32>(i).to_string();
            sort(bits.begin(), bits.end(), std::greater<int>());
            int count = 0, j = 0;
            while(bits[j] != '0'){
                count++;
                j++;
            }
            ans[i] = count;
        }

        return ans;
    }
};

// Approach: Bit Manipulation, Dynamic Programming
// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for(int i = 0; i <= n; i++){
            ans[i] = ans[i >> 1] + ( i & 1 );
        }

        return ans;
    }
};
