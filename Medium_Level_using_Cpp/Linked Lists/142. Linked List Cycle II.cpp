// Problem - 142. Linked List Cycle II
// Link - https://leetcode.com/problems/linked-list-cycle-ii/description/
// Topics - Hash Table, Linked List, Two Pointers
// Time Complexity - O(n) - The slow and fast pointers traverse the list at most twice: once to detect the cycle and once to find the start of the cycle.
// Space Complexity - O(1) - Only constant extra space is used for the pointers.
// Solution - 

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // FLOYD CYCLE DETECTION ALGORITHM
        if(!head || !head->next){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // DETECT IF A CYCLE EXISTS
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break; // CYCLE DETECTED
            }
        }

        if(!fast || !fast->next){
            return nullptr;
        }

        // FIND START OF THE CYCLE
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
}; 
