// Problem : 215. Kth Largest Element in an Array
// Link - https://leetcode.com/problems/kth-largest-element-in-an-array/
// Time Complexity - O(n log k) - building heap - log k
// Space Complexity - O(k)
// Topics - Array, Divide And Conquer, Min Heap, Sorting, Quick Select
// Solution - 
// Approach - Min Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num: nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
           
        }
        return minHeap.top();
    }
};