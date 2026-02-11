/*
Problem: 326. Power of Three
Link: https://leetcode.com/problems/power-of-three/description/?envType=problem-list-v2&envId=wv5ww91e
Topics:
Level: Easy
*/

// O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }

        return n > 0 && 1162261467 % n == 0;
    }
};

// O(n) - Recursion
class Solution {
public:
    bool isPowerOfThree(int n) {
       if(n <= 0){
            return false;
       }

       while(n % 3 == 0){
            n /= 3;
       }

       return n == 1;
    }
};
