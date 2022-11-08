//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    bool dp[n][sum+1];
	    memset(dp,0,sizeof(dp));
	    if(arr[0]<=sum)dp[0][sum]=1;
	    for(int i=0;i<n;i++)dp[i][0]=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            dp[i][j]=dp[i-1][j];
	            if(j-arr[i]>=0)
	            dp[i][j]=dp[i][j]||dp[i-1][j-arr[i]];
	        }
	    }
	    int ans=INT_MAX;
	    for(int j=0;j<=sum;j++)
	    {
	        if(dp[n-1][j]==true)
	        ans=min(ans,abs((sum-j)-j));
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends