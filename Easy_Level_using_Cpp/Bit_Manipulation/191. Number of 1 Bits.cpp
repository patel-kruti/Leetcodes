/*
191. Number of 1 Bits
Link - https://leetcode.com/problems/number-of-1-bits/?envType=problem-list-v2&envId=wv5ww91e
Topics - Bit Manipulation, Divide and Conquer
*/

// 191. Number of 1 Bits

class Solution {
public:
    int hammingWeight(int n) {

        int ans = 0;
        
        while(n > 0){
            if(n % 2 == 1){
                ans++;
            }
            n = n /2;
        }

        return ans;
    }
};


// Bit Manipulation - Brian Kernighan’s algorithm
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n){
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};
