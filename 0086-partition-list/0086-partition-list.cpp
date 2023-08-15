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
    ListNode* partition(ListNode* head, int x) {
     ListNode *temp=head;
        vector<int>temp1;
        while(temp)
        {
            temp1.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>y,z,w;
        for(int i=0;i<temp1.size();i++)
        {
            if(temp1[i]==x)
                y.push_back(i);
            else if(temp1[i]>x)
                z.push_back(i);
            else w.push_back(i);
        }
        vector<int>final;
        for(auto it:w)
        {
            final.push_back(it);
        }
        for(int i=0;i<temp1.size();i++)
        {
            if(find(final.begin(),final.end(),i)==final.end())
                final.push_back(i);
        }
        for(auto it:final)cout<<it;
        ListNode* head1=new ListNode();
        ListNode* ans=head1;
        if(final.size()==0)return head;
        else
        {
            head1->val=(temp1[final[0]]);
            for(int i=1;i<final.size();i++)
            {
                
                head1->next=new ListNode(temp1[final[i]]);
                head1=head1->next;
            }
        }
        return ans;
    }
};