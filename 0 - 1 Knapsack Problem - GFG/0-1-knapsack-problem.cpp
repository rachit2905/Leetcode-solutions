//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int help( int wt[], int val[],vector<vector<int>>&dp,int W,int ind,int n)
    {
        if(ind==0 || W==0)return 0;
        if(dp[ind][W]!=0)return dp[ind][W];
        if(W-wt[ind-1]>=0) dp[ind][W]=max(dp[ind][W]+help(wt,val,dp,W,ind-1,n),dp[ind][W]+val[ind-1]+help(wt,val,dp,W-wt[ind-1],ind-1,n));
    
        else dp[ind][W]+=help(wt,val,dp,W,ind-1,n);
        return dp[ind][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       //memset(dp,0,sizeof(dp));
       help(wt,val,dp,W,n,n);
    //   for(int i=0;i<=n;i++)
    //   {
    //       for(int j=0;j<=W;j++)
    //       cout<<dp[i][j]<<" ";
    //       cout<<"\n";
    //   }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends