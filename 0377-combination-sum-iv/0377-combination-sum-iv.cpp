class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       unsigned long long int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        //for(int i=0;i<nums.size();i++)dp[nums[i]]=1;
        
            for(int j=1;j<=target;j++)
            {
                for(int i=0;i<nums.size();i++)
        {
                if(nums[i]<=j)
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};