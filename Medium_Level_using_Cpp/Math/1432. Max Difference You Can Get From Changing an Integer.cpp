// Problem : 1432. Max Difference You Can Get From Changing an Integer
// link : https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15
// Topics : Math, Greedy
// Solution : 
class Solution {
public:
    int maxDiff(int num) {
        string a, b;
        char x, y;

        // First Iteration
        string tempStr = std::to_string(num);
        a = tempStr;
        b = tempStr;
        int numLen = tempStr.length();
        
        if(tempStr[0] == '9'){
            int i = 1;
            while(i < numLen && tempStr[i] == '9') {
                i++;
            }
            if(i == numLen){
                x = '9';
            } else {
                x = tempStr[i];
            }
            y = '9';
        } else {
            x = tempStr[0];
            y = '9';
        }

        for(int i = 0; i < numLen; i++){
            if(a[i] == x){
                a[i] = y;
            }
        }

        // Second Iteration
        if(tempStr[0] == '1'){
            int i = 0;
            while(i < numLen && (tempStr[i] == '1' || tempStr[i] == '0')){
                i++;
            }
            if(i == numLen){
                x = '1';
                y = '1';
            } else {
                if(tempStr[1] == '1' || tempStr[1] == '0'){
                    x = tempStr[i];
                } else {
                    x = tempStr[1];
                }
                y = '0';
            }
        } else {
            x = tempStr[0];
            y = '1';
        }

        for(int i = 0; i < numLen; i++){
            if(b[i] == x){
                b[i] = y;
            }
        }
        
        return std::stoi(a) - std::stoi(b);
    }
};
