/*
Problem: 342. Power of Four
Link: https://leetcode.com/problems/power-of-four/description/?envType=problem-list-v2&envId=wv5ww91e
Topics: Math, Bit Manipulation, Recursion
Level: Easy
*/

// Approach: Math
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        double p = log(n) / log(4);

        if(p - int(p) == 0){
            return true;
        }
        return false;
    }
};

// Approach: Recursion
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        while(n % 4 == 0){
            n /= 4;
        }
        return n == 1;
    }
};

// Approach: Bit Manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && 
        (n & (n - 1)) == 0 &&  // n % 2 == 0 -> divide by 4 is also divisible by 2
        (n & 0x55555555) != 0; // Bit Mask for Even 1 bits -> 0x55555555. 4 = 0000 0100, 16 = 0001 0000, 64 = 0100 0000
    }
};
