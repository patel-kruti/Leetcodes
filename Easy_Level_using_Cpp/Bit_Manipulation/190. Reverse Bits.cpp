/*
190. Reverse Bits
Link - https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=wv5ww91e
Topics: Bit Manipulation, D&C
Level - Easy
*/

// Takes more momory but faster than D&C
class Solution {
public:
    int reverseBits(int n) {
        if(n == 0){
            return n;
        }
        double ans = 0;

        int reminder = 0;
        string tempBits = "";

        // Get the number in bits
        while(n > 0){  
            reminder = n % 2;
            n = n / 2;
            tempBits += to_string(reminder);
        }

        // Add trailing zeros to make it 32 bit
        int bitLen = tempBits.length();
        if( bitLen < 32){
            for(int i = bitLen; i < 32; i++){
                tempBits += "0";
            }            
        }

        // Generate the new number
        int cnt = 31;
        for(int i = 0; i < 32; i++){
            if (tempBits[i] == '1'){
                ans += 1 * pow(2, cnt);
            }    
            cnt--;
        }

        return ans;
    }
};



// Divide and Conquer (In Place -> Saves Memory)
class Solution {
public:
    int reverseBits(int n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
