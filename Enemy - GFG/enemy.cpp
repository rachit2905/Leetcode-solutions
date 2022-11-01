//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &e)
        {
            //  code here
             if(k==0){
                return n*m;
            }
            vector<int> row,col;
            for(auto it:e){
                row.push_back(it[0]);
                col.push_back(it[1]);
            }
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            int maxrow=max(row[0]-1,n-row[k-1]),maxcol=max(col[0]-1,m-col[k-1]);
            for(int i=1;i<k;i++){
                maxrow=max(maxrow,row[i]-row[i-1]-1);
            }
            for(int i=1;i<k;i++){
                maxcol=max(maxcol,col[i]-col[i-1]-1);
            }
            return maxrow*maxcol;
        
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends