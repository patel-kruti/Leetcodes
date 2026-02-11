/*
Problem: 292. Nim Game
Link: 
Topics: Math, Brain Teaser, Game Theory 
Level: Easy
*/

// Time: O(1)
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
