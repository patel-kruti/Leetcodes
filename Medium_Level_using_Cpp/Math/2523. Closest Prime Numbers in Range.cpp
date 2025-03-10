// Problem: 2523. Closest Prime Numbers in Range
// Link: https://leetcode.com/problems/closest-prime-numbers-in-range/
// Topic: Math, Number Theory
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Solution:

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            // 1. Find all Prime Numbers
            // 2. Find distance between adjacent prime numbers
            // 3. Return pair with minimum distance
            vector<int> primes;
    
            int N = right + 1;
            vector<bool> isPrime(N, true);
            isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
    
            for (int i = 2; i * i < N; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j < N; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            // Step 2: Collect primes in the range [left, right]
            for (int num = left; num <= right; num++) {
                if (isPrime[num]) {
                    primes.push_back(num);
                }
            }
    
            if(primes.size() == 0 || primes.size() == 1 ){
                return {-1, -1};
            }
    
            vector<int> ans(2);
            int minDistance = primes[1] - primes[0];
            ans[0] = primes[0];
            ans[1] = primes[1];
            for(int i = 1; i < primes.size() - 1; i++){
                if((primes[i + 1] - primes[i]) < minDistance){
                    ans[0] = primes[i];
                    ans[1] = primes[i + 1];
                    minDistance = primes[i + 1] - primes[i];
                }
            }
    
            return ans;
        }
    };
