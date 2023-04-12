class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,i=0,j=0,ze=0,sz=INT_MIN;
        for(j=0;j<nums.size();j++)
        {
           if(nums[j]==1)ze++;
           if(j-i+1-ze>k)
           {
               if(nums[i]==1)
                   ze--;
               i++;
           }
            sz=max(sz,j-i+1);
            
            
        }
        return sz;
        
    }
};