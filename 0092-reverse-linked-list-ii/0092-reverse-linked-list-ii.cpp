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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int co=1;
        ListNode* prev=NULL;
        
        ListNode* curr=head;
        while(co!=left)
        {
            co++;prev=curr;curr=curr->next;
        }
        ListNode*temp=prev;ListNode* temp1=curr;
        while(co!=right+1)
        {
            co++;
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        
        if(temp!=NULL)
            temp->next=prev;
        else
            head=prev;
        temp1->next=curr;
        return head;
    }
};