class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
           int minScore=nums[0];
        for (auto n: nums) minScore &= n;
        
        if (minScore!=0) return 1;

        int ans=0,t=nums[0];
        for (int i=0;i<nums.size();i++){
            t &= nums[i];
            if (t==0){
                ans++;
                t = (i+1<nums.size()?nums[i+1]:0);
            }
        }
        

        return ans;
    }
};