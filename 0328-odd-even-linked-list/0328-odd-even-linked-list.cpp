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
    ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next)
        return head;
      ListNode *p1 = head, *p2 = head->next;
      while (p2 && p2->next) {
        ListNode* t = p1->next;
        p1->next = p2->next;
        p1 = p1->next;
        p2->next = p2->next->next ? p2->next->next : nullptr;
        p1->next = t;
        p2 = p2->next;
      }
      return head;
    }
};