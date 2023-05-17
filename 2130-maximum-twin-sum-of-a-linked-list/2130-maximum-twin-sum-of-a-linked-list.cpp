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
    int pairSum(ListNode* head) {
        vector<int>v1;
        while(head!=NULL)
        {
            v1.push_back(head->val);
            head=head->next;
        }
        //cout<<v1.size();
        int i=0,j=v1.size()-1,ans=0;
        while(i<j)
        {
            ans=max(ans,v1[i]+v1[j]);
            i++;
            j--;cout<<ans<<" ";
        }
        return ans;
    }
};