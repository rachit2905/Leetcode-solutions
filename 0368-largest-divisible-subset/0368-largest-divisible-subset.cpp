class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<=i-1;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                hash[i]=j;
                }
            }
        }
        int an=-1,in=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>an)
            {
                an=dp[i];
                in=i;
            }
        }
        ans.push_back(nums[in]);
        while(hash[in]!=in)
        {
            in=hash[in];
            ans.push_back(nums[in]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};