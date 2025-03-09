// Problem: 1780. Check if Number is a Sum of Powers of Three
// Source: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Time Complexity: O(logn)
// Space Complexity: O(1)
// topic: Math
// Difficulty: Medium
// Solution 1:
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            vector<int> powersOfThree = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163};
            int currPower = 17;
            while( n > 0 && currPower > 0){
                for(int i = currPower; i >= 0; i--){
                    if(n >= powersOfThree[i]){
                        n -= powersOfThree[i];
                        currPower = i;
                    }
                }
            }
            if(n == 0){
                return true;
            } else {
                return false;
            }
        }
    };

// Solution 2:
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n > 0){
                if(n % 3 == 2){
                    return false;
                }
                n /= 3;
            }
            return true;
        }
    };
