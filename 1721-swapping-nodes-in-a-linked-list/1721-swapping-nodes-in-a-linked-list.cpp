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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* temp=head;int n=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        temp=head;
        int i=0;
        while(temp && i!=n-k)
        {
            temp=temp->next;
            i++;
        }
        ListNode* temp1=head;
        int j=0;
        while(temp1 && j!=k-1)
        {
            temp1=temp1->next;
            j++;
        }
        int x=temp1->val;
        temp1->val=temp->val;
        temp->val=x;
        return head;
    }
};