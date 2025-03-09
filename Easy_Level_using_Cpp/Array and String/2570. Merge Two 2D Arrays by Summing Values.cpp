// Problem: 2570. Merge Two 2D Arrays by Summing Values
// Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
// Difficulty: Easy
// Time Complexity: O(n * m)
// Space Complexity: O(1)
// Topics: Array, Two Pointers, Hash table
// Solution:
class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int len1 = nums1.size(), len2 = nums2.size();
            vector<vector<int>> result;
            int p1 = 0, p2 = 0;
    
            while(p1 < len1 && p2 < len2){
                if(nums1[p1][0] < nums2[p2][0]){
                    result.emplace_back(nums1[p1]);
                    p1++;
                } else if(nums1[p1][0] > nums2[p2][0]){
                    result.emplace_back(nums2[p2]);
                    p2++;
                } else{
                    vector<int> temp = {nums1[p1][0], nums1[p1][1] + nums2[p2][1]};
                    result.emplace_back(temp);
                    p1++;
                    p2++;
                } 
            }
    
            while(p1 < len1){
                result.emplace_back(nums1[p1]);
                p1++;
            }
    
            while(p2 < len2){
                result.emplace_back(nums2[p2]);
                p2++;
            }
    
            return result;
        }
    };