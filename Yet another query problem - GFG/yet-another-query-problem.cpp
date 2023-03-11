//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        int dp[N][N+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            for(int j=N-1;j>=i;j--)
            {
                if(A[j]==A[i])
                dp[i][j]=dp[i][j+1]+1;
                else
                dp[i][j]=dp[i][j+1];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<"\n";
            
        }
        vector<int>ans;int co=0;
        for(auto it:Q)
        {
            co=0;
            vector<int>v1=it;
            for(int i=v1[0];i<=v1[1];i++)
            {
                if(dp[i][i]==v1[2])
                co++;
            }
            ans.push_back(co);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends