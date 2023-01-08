class Solution {
public:
    int numDistinct(string s, string t) {
         static int MOD = (int)1e9 + 7;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<n+1; i++){
            dp[i][m] = 1;
        }

        for(int i=n-1; i>=0; i--){
            int ans;
            for(int j=m-1; j>=0; j--){
                if(s[i] == t[j]){
                    ans = dp[i+1][j+1]%MOD + dp[i+1][j]%MOD;
                }
                else{
                    ans = dp[i+1][j];
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
};