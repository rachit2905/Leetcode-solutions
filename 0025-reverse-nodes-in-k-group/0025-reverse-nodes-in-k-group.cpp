class Solution {
public:
int lengthh(ListNode* head)
{
    int length=0;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    return length;
}
ListNode* rec(ListNode* head, int k, int length)
{
    if(length<k)
    return head;
    int c=0;
    ListNode* prev=NULL,*curr=head,*nex=NULL;
    while(curr!=NULL && c<k)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        c++;
    }
    if(nex!=NULL)
    {
        head->next=rec(nex,k,length-k);
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l=lengthh(head);
        return rec(head,k,l);
    }
};