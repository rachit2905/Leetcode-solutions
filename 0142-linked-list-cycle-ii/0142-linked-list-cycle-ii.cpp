/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         unordered_map<ListNode*,int>m1;
        if(head==NULL){
          return NULL;
        }
        while(m1[head]==0){
          m1[head]++;
          if(head->next==NULL){
            return NULL;
          }
          head=head->next;
        }
        return head;
    }
};