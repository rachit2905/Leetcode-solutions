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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(vector<int>&nums,int left,int right)
 {
     if(left > right)
     {
         return NULL;
     }
     int mid = left + (right - left)/2;

     TreeNode *temp = new TreeNode(nums[mid]);

     // left recursion
     temp->left = helper(nums,left,mid-1);
     temp->right = helper(nums,mid+1,right);

     return temp;
 }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        ListNode *curr = head;
        while(curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }

        return helper(v,0,v.size()-1);

    }
};