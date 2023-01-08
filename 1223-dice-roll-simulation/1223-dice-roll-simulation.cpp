class Solution {
public:
    int mod = 1e9+7;
int solve(int n,vector<int>&rollMax,int prev,int times,vector<vector<vector<int>>>&dp){
	if(n==0) return 1;
	int ways = 0;
	if(dp[n][prev][times]!=-1) return dp[n][prev][times];
	for(int i=1;i<=6;i++){
		if(i==prev&&1+times<=rollMax[prev-1]){
			ways = (ways + (solve(n-1,rollMax,prev,times+1,dp)%mod))%mod;
		}
		if(i!=prev){
			ways = (ways + (solve(n-1,rollMax,i,1,dp)%mod))%mod;
		}
	}
	return dp[n][prev][times] = ways%mod;
}
    int dieSimulator(int n, vector<int>& rollMax) {
        int maxel = *max_element(rollMax.begin(),rollMax.end());
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(8,vector<int>(maxel+10,-1)));
	return solve(n,rollMax,7,0,dp);
    }
};