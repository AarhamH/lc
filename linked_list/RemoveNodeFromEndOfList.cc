/*
  Leetcode 19: Remove Nth Node From End of List (MEDIUM)

  You are given the beginning of a linked list head, and an integer n.

  Remove the nth node from the end of the list and return the beginning of the list.

  Example 1:

  Input: head = [1,2,3,4], n = 2

  Output: [1,2,4]

  Example 2:

  Input: head = [5], n = 1

  Output: []

  Example 3:

  Input: head = [1,2], n = 2

  Output: [2]

*/
class Solution {
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* dummy = head;
        while(dummy != nullptr) {
            length++;
            dummy = dummy->next;
        }

        int diff = length - n;
        if(diff == 0) {
            return head->next;
        }
        
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr) {
            if(count == diff) {
                prev->next = curr->next;
                break;
            }
            count++;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
