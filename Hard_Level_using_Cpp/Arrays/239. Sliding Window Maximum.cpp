// Problem - 239. Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Difficulty: Hard
// Topics: Arrays, Sliding Window, Deque
// Approach: Using Deque
// Time Complexity: O(n)
// Space Complexity: O(n)
// Solution:-
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            // ensures dq contains index within window
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            // remove smaller elements from dq
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // add current element in the queue
            dq.push_back(i);

            // push current window max
            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};