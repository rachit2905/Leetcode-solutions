//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
       
     int solveTab(string s1,string s2,vector<vector<int>>&dp)
     {
         for(int i=s1.size()-1;i>=0;i--)
         {
             for(int j=s2.size()-1;j>=0;j--)
             {
                 int del=INT32_MAX,nod=INT32_MAX;
                 if(s1[i]==s2[j])
                 {
                     int p=0;
                     nod=dp[i+1][j+1];
                     
                     if((i+1)>=s1.size()||(j+1)>=s2.size())
                     {
                         p=abs(i-j);
                          nod=p;
                     }
                    
                 }
                 else
                 {
                     int r=dp[i+1][j]+1;
                     int l=dp[i][j+1]+1;
                     if((i+1)>=s1.size())
                     {
                        r=abs(i+1-j)+1;
                     }
                     if((j+1)>=s1.size())
                     {
                         l=abs(j+1-i)+1;
                     }
                     del=min(r,l);
                 }
                 dp[i][j]=min(del,nod);
             }
         }
         return(dp[0][0]);
     }
    int minimumNumberOfDeletions(string S) { 
        // code here
        vector<vector<int>>dp(S.size()+1,vector<int>(S.size()+1,0));
        string str=S;
        reverse(str.begin(),str.end());
        return(solveTab(S,str,dp)/2);
    } 
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends