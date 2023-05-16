//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isPower5(string &s,int i,int j){
        if (s[i] == '0') return false;  
        long long num = 0;
        for (int k = i; k <= j; k++)num = num * 2 + (s[k] - '0');
        while (num > 1) 
        {
            if (num % 5 != 0) return false;
            num /= 5;
        }
        return true;
    }
    
       int solve(string &s, int i, int n, vector<int> &dp){
        if(isPower5(s, i, n)) return 1;
        if(i==n) return INT_MAX;
        
        
        if(dp[i]!=INT_MAX) return dp[i];
        int mini = INT_MAX;
        
        for(int j=i; j<=n; j++){
            if(isPower5(s,i,j)){
                
                int ans = solve(s, j+1, n, dp);
                if(ans<INT_MAX){
                    ans++;
                }
                
                mini = min(mini, ans);
                dp[i] = mini;
            }
        }
        return mini;
    }
    
    
    
    int cuts(string s){
        vector<int> dp(s.size(), INT_MAX);
        int ans = solve(s, 0, s.size()-1, dp);
        return ans==INT_MAX?-1: ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends