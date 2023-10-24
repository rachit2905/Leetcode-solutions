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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL or head->next==NULL) return NULL;
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            length++;
            temp = temp->next;
        }
        // required length:
        ListNode* temp1 = head;
        int required = length - n;
        if(required == 0) return head->next;
        int count = 1;
        while(count <= required) {
            if(count == required) {
                temp1->next = temp1->next->next;
                return head;
            }
            else {
                count++;
                temp1 = temp1->next;
            }
        }
        return head;
    }
};