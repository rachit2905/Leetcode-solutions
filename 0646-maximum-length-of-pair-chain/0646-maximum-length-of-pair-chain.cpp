class Solution {
public:
    int n;
    int dp[1001];
    int binary_s(int l,vector<vector<int>>& pairs,int curr_end)
    {
        int r=n-1;
        int ans_i=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(pairs[mid][0]>curr_end)
            {
                ans_i=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans_i;
    }
    int solve(int i,vector<vector<int>>& pairs)
    {
        
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int not_taken= solve(i+1,pairs);
        int neww_i=binary_s(i+1,pairs,pairs[i][1]);
        int taken=1+solve(neww_i,pairs);
        
        return dp[i]=max(not_taken,taken);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solve(0,pairs);
        
    }
};