class Solution {
public:
    int findTargetSumWays(vector<int>& num, int targets) {
            int totSum = 0;
         int n=num.size();
    for(int i=0; i<n;i++){
        totSum += num[i];
    }
    
    //Checking for edge cases
    if(totSum-targets <0 || (totSum-targets)%2 ) return 0;
        int tar=(totSum-targets)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken);
        }
    }
    return dp[n-1][tar];
    
    }
};