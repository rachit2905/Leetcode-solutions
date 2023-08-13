class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n+2,true);

        for(int i=n-1;i>=0;i--){
            bool ans=false;
            if(i<n-1 && nums[i]==nums[i+1]){
                if(dp[i+2]){
                    ans=true;
                }
            }
            if(i<n-2 && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                if(dp[i+3]){
                    ans=true;
                }
            }
            if(i<n-2 && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
                if(dp[i+3]){
                    ans=true;
                }
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};