//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
     int stoneTraversal(vector<int>& arr, int idx, int n, vector<bool>& vis, vector<int>& dp){

        if(idx >= n || idx<0) return 1;

        if(dp[idx]!=-1) return dp[idx];

        if(vis[idx]) return 0;

        vis[idx] = 1;

        return dp[idx] = stoneTraversal(arr, idx + arr[idx], n, vis, dp);

    }

    int goodStones(int n,vector<int> &arr){

        

        vector<int> dp(n, -1);

        vector<bool> vis(n, 0);

        

        for(int i=0;i<n;i++){

            if(!vis[i]){

                stoneTraversal(arr, i, n, vis, dp);

            }

        }

        int cnt = 0;

        for(int i=0;i<n;i++){

            if(dp[i] == 1) cnt++;

        }

        return cnt;

    }  

};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends