class Solution {
    int DR[8] = {-2,-1,1,2,2,1,-1,-2};
    int DC[8] = {-1,-2,-2,-1,1,2,2,1};
public:
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n+1,vector<double>(n+1,0)));
        //Follow The base case 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[0][i][j] = 1; //If move == 0 then probability is 1 as discussed above
            }
        }
        for(int moves = 1; moves <= k; moves++){
            for(int srow = 0; srow < n; srow++){
                for(int scol = 0; scol < n; scol++){
                    double probability = 0;
                    for(int k = 0; k < 8; k++){ //move the knight in eight direction
                        int nrow = DR[k] + srow;
                        int ncol = DC[k] + scol;
                        if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= n)
                            continue;
                        else
                            probability += 0.125*dp[moves-1][nrow][ncol]; //in each direction probabity of being inside the board is (probability/8)
                    }
                    dp[moves][srow][scol] = probability;
                }
            }
        }
        return dp[k][row][col];
    }
};