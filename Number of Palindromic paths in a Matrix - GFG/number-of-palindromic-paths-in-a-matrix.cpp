//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int n,m;
    long mod=1000000007;
    int rec(int i1, int j1, int i2, int j2, vector<vector<char>>& matrix, map<vector<int>,int>& dp){
        if(i1<0 || j1<0 || i2<0 || j2<0 || i1>=n || i2<i1 || j1>=m || j2<j1){
            return 0;
        }
        
        if(matrix[i1][j1]!=matrix[i2][j2]) return 0;
        if(abs((i2-i1)+(j2-j1))<=1) return 1;
        if(dp.find({i1,j1,i2,j2})!=dp.end()) return dp[{i1,j1,i2,j2}];
        int ans=0;
        ans=ans%mod+rec(i1+1,j1,i2,j2-1,matrix,dp)%mod;
        ans=ans%mod+rec(i1+1,j1,i2-1,j2,matrix,dp)%mod;
        ans=ans%mod+rec(i1,j1+1,i2,j2-1,matrix,dp)%mod;
        ans=ans%mod+rec(i1,j1+1,i2-1,j2,matrix,dp)%mod;
        return dp[{i1,j1,i2,j2}]=ans;
    }
  
    int countPalindromicPaths(vector<vector<char>>matrix){
        n=matrix.size();
        m=matrix[0].size();
        map<vector<int>,int> dp;
        return rec(0,0,n-1,m-1,matrix,dp)%mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.countPalindromicPaths(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends