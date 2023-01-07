class Solution {
public:
    int countVowelPermutation(int n) {
         vector<long long> dp(5,1);

        long long a,b,c,d,e;
        for(int i=1;i<n;i++){
            a=dp[0];
            b=dp[1];
            c=dp[2];
            d=dp[3];
            e=dp[4];

            dp[0]=(b+c+e)%1000000007;
            dp[1]=(a+c)%1000000007;
            dp[2]=(b+d)%1000000007;
            dp[3]=c%1000000007;
            dp[4]=(c+d)%1000000007;

        }
        return (dp[0]+dp[1]+dp[2]+dp[3]+dp[4])%1000000007;
    }
};