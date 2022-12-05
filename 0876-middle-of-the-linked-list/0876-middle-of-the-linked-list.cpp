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
     ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode *ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        int n=(count/2) + 1,k=1;
        while(k<n){
            head=head->next;
            k++;
        }
        return head;
    }
};