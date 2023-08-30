class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
         int n=nums.size();
       long long ans=0;
       long long minMaxvalue=nums[n-1];
       for (int i=n-2;i>=0;i--)
       {
         long long parts=ceil(nums[i]/(double)minMaxvalue);
         ans+=parts-1;
         minMaxvalue=nums[i]/parts;
       }  
       return ans;
    }
};