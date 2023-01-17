class Solution {
public:
    int minFlipsMonoIncr(string s) {
          int n = s.size();
        vector<int> dp(n+1,0);
        int num = 0 ;
        for(int i = 1 ; i <= n ; ++i )
        {   if(s[i-1]=='1')++num;
            if( s[i-1] == '1') // 0...i-1 is already monotonic hence 1 no need to flip. 0000  then 1 append then formed is monotonic   000111 then 1 append then also its monotonic
            dp[i] = dp[i-1];
            else 
            {
                dp[i] = min(num,dp[i-1]+1); // otherwise 2 case consider flip or not flip . 
            }
           
        }
        return dp[n];
    }
};