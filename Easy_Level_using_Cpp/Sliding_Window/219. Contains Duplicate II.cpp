/*
Problem: 219. Contains Duplicate II
Link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=problem-list-v2&envId=wv5ww91e
Topics: Array, Hash Table, Sliding Window
Level: Easy
*/

// A solution using Hash Table O(n^2)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> umap;

        for(int i = 0; i < nums.size(); i++){
            auto it = umap.find(nums[i]);
            if(it != umap.end()){
                for(int ind : it->second){
                    if(abs(ind - i) <= k){
                        return true;
                    }
                }
                umap[nums[i]].push_back(i);
            } else {
                umap[nums[i]] = {i};
            }
        }

        return false;
    }
};

// Optimal Solution - O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset; // Hash Table in cpp

        // Iterate through the array once, while storing only last k values in the map -> Sliding Window
        for(int i = 0; i < nums.size(); i++){
            if(uset.count(nums[i])){  // Constant Time - O(1), worst  - O(log n)
                return true;
            }

            uset.insert(nums[i]);  // O(1)

            if(uset.size() > k){
                uset.erase(nums[i - k]);  // O(1)
            }
        }

        return false;
    }
};

