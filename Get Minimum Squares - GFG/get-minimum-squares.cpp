//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    // Code here
	     vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int count=1;
        while(count*count<=n)
        {
            for(int i=count*count;i<=n;i++)
            {
                dp[i]=min(dp[i-count*count]+1,dp[i]);
            }
            count++;
        }
        return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends