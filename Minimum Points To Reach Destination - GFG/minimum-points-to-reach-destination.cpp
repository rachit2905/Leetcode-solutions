//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(vector<vector<int>> points, int m, int n) 
	{ 
	    // Your code goes here
	    int dp[m][n];
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)dp[i][j]=0;
	    }
	    for(int i=m-1;i>=0;i--)
	    {
	        for(int j=n-1;j>=0;j--)
	        {
	            if(i==m-1 && j==n-1)
	            {
	                dp[i][j]=max(1,1-points[i][j]);
	            }
	            else if(i==m-1)
	            {
	                dp[i][j]=max(1,dp[i][j+1]-points[i][j]);
	            }
	            else if(j==n-1)
	            {
	                dp[i][j]=max(1,dp[i+1][j]-points[i][j]);
	            }
	            else
	            {
	                dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-points[i][j]);
	            }
	        }
	    }
	    return dp[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends