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
    
    void reorderList(ListNode* head) {
         ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
        }
        slow=reverse(slow);cout<<slow->val;
        while(head!=NULL && slow!=NULL)
        {
            ListNode* temp=head->next;
            head->next=slow;
            head=temp;
            temp=slow->next;
            slow->next=head;
            slow=temp;
        }
        if(head!=NULL)head->next=NULL;
        
    }
    ListNode* reverse(ListNode* slow)
    {
        ListNode *prev=NULL;
        while(slow!=NULL)
        {
            ListNode *nex=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nex;
        }
        return prev;
    }
};