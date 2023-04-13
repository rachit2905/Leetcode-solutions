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
    int help(ListNode *slow)
{
    ListNode* temp=slow;int ans=0;
    temp=temp->next;
    while(temp!=slow)
    {
        ans++;
        temp=temp->next;
    }
    return ans+1;
}
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                int x=help(slow);
                fast=slow=head;
                while(x--)
                {
                    fast=fast->next;
                }
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            };
        }
        return NULL;
    }
};