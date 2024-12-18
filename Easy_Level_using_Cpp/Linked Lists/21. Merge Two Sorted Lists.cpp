// Problem - 21. Merge Two Sorted Lists
// Link - https://leetcode.com/problems/merge-two-sorted-lists/description/
// Topics - Linked List, Recursion
// Time Complexity - O(n + m)
// Space Complexity - O(1) - Iterative, O(n + m) - stack space
// Solution - 

// Iterative Solution ----------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* mergedList;

        if(!h1 && !h2) return h1;
        if(!h1) return h2;
        if(!h2) return h1;

        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;

        if(h1->val < h2->val){
            mergedList = h1;
        } else {
            mergedList = h2;
        }
        while(h1 != nullptr && h2 != nullptr){
            if(h1->val < h2->val){
                while(h1 != nullptr && h1->val <= h2->val){
                    prev1 = h1;
                    h1 = h1->next;
                }  
                prev1->next = h2;
            } else {
                while(h2 != nullptr && h2->val <= h1->val){
                    prev2 = h2;
                    h2 = h2->next;
                }  
                prev2->next = h1;
            }
        }

        return mergedList;
    }
};

// Recursive Approach ----------------------------------------
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
