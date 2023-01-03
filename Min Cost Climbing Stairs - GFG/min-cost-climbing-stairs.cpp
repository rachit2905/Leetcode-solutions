//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        //Write your code here
        
        vector<int>dp(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(i<2)dp[i]=cost[i];
            else dp[i]=min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends