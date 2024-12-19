// Problem - 2. Add Two Numbers
// Link - https://leetcode.com/problems/add-two-numbers/description/
// Topics - Linked List, Math, Recursion
// Time Complexity - O(max (m, n))
// Space Complexity - O (max (m, n))
// Solution - 

//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* res = result;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;

        while(curr1 != nullptr || curr2 != nullptr || carry){
            ListNode* newNode = new ListNode();
            int currSum = carry;

            if(curr1 != nullptr){
                currSum += curr1->val;
                curr1 = curr1->next;
            }

            if(curr2 != nullptr){
                currSum += curr2->val;
                curr2 = curr2->next;
            }

            if(currSum > 9){
                newNode->val = currSum % 10;
            } else {
                newNode->val = currSum;
            }
            carry = currSum / 10;

            res->next = newNode;
            res = res->next;   
        }

        return result->next;
    }
};
