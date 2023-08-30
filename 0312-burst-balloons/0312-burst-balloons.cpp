class Solution {
public:
    int dp[302][302];
    int solve(vector<int>&arr,int i,int j)
    {
        if(dp[i][j]!=-1){return dp[i][j];}
    if(i>j){return 0;}
    int ans=0;
    for (int k = i; k <= j; k++)
    {
        ans=max(ans,arr[i-1]*arr[k]*arr[j+1]+solve(arr,i,k-1)+solve(arr,k+1,j));
    }
    return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
     return solve(nums,1,(int)nums.size()-2);
        for(int i=0;i<=nums.size()+1;i++)
        {
            for(int j=0;j<=nums.size()+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
            
        }
        
    return 0;
    }
};