//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        void recursion(int i,int j,vector<vector<int>>&grid,int n,int m){

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){

            return ;

        }

        grid[i][j]=0;

        recursion(i+1,j,grid,n,m);

        recursion(i-1,j,grid,n,m);

        recursion(i,j+1,grid,n,m);

        recursion(i,j-1,grid,n,m);

    }

    int numberOfEnclaves(vector<vector<int>> &grid) {

        // Code here

        int n = grid.size();

        int m = grid[0].size();

        

        for(int i =0;i<n;i++){

            for(int j =0;j<m;j++){

                if((i==0 ||j==0 || i==n-1 ||j==m-1) && grid[i][j]==1){

                    recursion(i,j,grid,n,m);

                }

            }

        }

        

        int count = 0;

        for(int i =0;i<n;i++){

            for(int j =0;j<m;j++){

                if(grid[i][j]==1){

                    count++;

                }

            }

        }

        return count;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends