//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n];
       memset(dp,0,sizeof(dp));
       int ans=0;
       for(int i=0;i<n;i++)
       {
           int st=ans;
           while(st!=0 && dp[st-1]>=a[i])
           {
               st--;
           }
           dp[st++]=a[i];
           ans=max(ans,st);
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends