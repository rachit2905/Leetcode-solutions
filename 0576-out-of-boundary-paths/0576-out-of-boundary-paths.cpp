class Solution {
public:
    int mod=(int)pow(10,9)+7;
    int findPaths(int m, int n, int maxMoves, int startRow, int startColumn) {
        vector<vector<vector<long int>>>dp(m,vector<vector<long int>>(n,vector<long int>(maxMoves+1,0)));
        for(int maxMove{1};maxMove<=maxMoves;++maxMove){
            for(int i{0};i<m;++i){
                for(int j{0};j<n;++j){
                    long int left=0;
                    if(j-1>=0)
                        left=dp[i][j-1][maxMove-1];
                    else
                        left=1;

                    long int right=0;
                    if(j+1<n)
                        right=dp[i][j+1][maxMove-1];
                    else
                        right=1;

                    long int up=0;
                    if(i-1>=0)
                        up=dp[i-1][j][maxMove-1];
                    else
                        up=1;
                    long int bottom=0;
                    if(i+1<m)
                        bottom=dp[i+1][j][maxMove-1];
                    else 
                        bottom=1;
                    
                    dp[i][j][maxMove]=(left+right+up+bottom)%mod;
                }
            }
        }
        return dp[startRow][startColumn][maxMoves]%mod;
    } 

};