class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=s.size()-2; i>=0; i--){
            for(int j=i+1; j<=s.size()-1; j++){
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};