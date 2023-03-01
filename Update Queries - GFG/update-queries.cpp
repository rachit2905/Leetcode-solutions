//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int n,int q,vector<vector<int>> &u)
        {
            // code here
            vector<int>ans(n,0);
            vector<vector<int>>temp(n,vector<int>(31,0));
            for(int i=0;i<q;i++)
            {
                int l=u[i][0]-1;
                int r=u[i][1];
                int x=u[i][2];
                for(int j=0;j<31;j++)
                {
                    if((1<<j) & x){temp[l][j]++;
                    if(r<n)temp[r][j]--;}
                }
            }
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<31;j++)
                {
                    temp[i][j]+=temp[i-1][j];
                }
            }
            for(int i=0;i<n;i++)
            {
                int x1=0;
                for(int j=0;j<31;j++)
                {
                    if(temp[i][j])
                    x1|=(1<<j);
                }
                ans[i]=x1;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends