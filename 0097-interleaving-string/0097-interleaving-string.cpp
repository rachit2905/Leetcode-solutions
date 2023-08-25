class Solution {
public:
    bool solve(string s1, string s2, string s3){
        if(s1.empty() && s2.empty() && s3.empty() ){
            return true;
        }
        if(s3.empty()){
            return false;
        }
        return ((s1[0]==s3[0] && solve(s1.substr(1),s2,s3.substr(1)))||(s2[0]==s3[0] && solve(s1,s2.substr(1),s3.substr(1))));
        //O(2^n)
    }
    bool isInterleave(string s1, string s2, string s3) {
        //return solve(s1,s2,s3);

        //using bottomup approach
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=(n+m)){
            return 0;
        }

        bool dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                //s1 is empty
                else if(i==0){
                    if(s2[j-1]==s3[j-1]){
                        dp[i][j]=dp[i][j-1];
                    }
                }
                //s2 is empty
                else if(j==0){
                    if(s1[i-1]==s3[i-1]){
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else if(s1[i-1]!=s3[i+j-1]&& s2[j-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j-1];
                }
                else if(s1[i-1]==s3[i+j-1]&& s2[j-1]==s3[i+j-1]){
                    dp[i][j]=(dp[i][j-1]|| dp[i-1][j]);
                }


            }
        }
        return dp[n][m];
    }
};