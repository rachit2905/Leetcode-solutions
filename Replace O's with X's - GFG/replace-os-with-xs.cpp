//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
         vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int j=0;j<m;j++){

            if(mat[0][j]=='O')

            {

                q.push({0,j});

            }

            if(mat[n-1][j]=='O'){

                q.push({n-1,j});

            }

        }

         for(int i=0;i<n;i++){

            if(mat[i][0]=='O')

            {

                q.push({i,0});

            }

            if(mat[i][m-1]=='O'){

                q.push({i,m-1});

            }

        }

        while(!q.empty()){

        int row=q.front().first;

        int col=q.front().second;

        q.pop();

         vis[row][col]=1;

            int delrow[]={-1,0,1,0};

            int delcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){

                int nrow=row+delrow[i];

                int ncol=col+delcol[i];

                

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' &&vis[nrow][ncol]!=1){

                    q.push({nrow,ncol});

                    vis[nrow][ncol]=1;

                }

            }

        }

        vector<vector<char>>ans=mat;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(vis[i][j]==0 && mat[i][j]=='O'){

                    ans[i][j]='X';

                }

            }

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends