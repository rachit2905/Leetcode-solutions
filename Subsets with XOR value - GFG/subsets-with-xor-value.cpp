//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:

    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
         int mx=arr[0];
        for(int i=1;i<N;i++)
            mx = max(arr[i], mx);
        
        //max possible xor value
        int max_xor = (1<<(int)(log2(mx)+1))-1;
        if(K>max_xor) return 0;
        
        int dp[N+1][max_xor+1];
        memset(dp, 0, sizeof dp);
        
        dp[0][0]=1;
        
        for(int i=1;i<=N;i++)
            for(int j=0;j<=max_xor;j++)
                dp[i][j] = dp[i-1][j]+dp[i-1][j^arr[i-1]];
        return dp[N][K];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends