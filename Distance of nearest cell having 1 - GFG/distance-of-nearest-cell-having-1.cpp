//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int distance(int i,int j,int n,int m,vector<vector<int>>& grid)

    {

        queue<pair<int,int>>q;

        q.push({i,j});

        int row[] = {-1, 0, +1, 0}; 

    int col[] = {0, +1, 0, -1};

        while(!q.empty())

        {

            int i1=q.front().first;

            int j1=q.front().second;

            q.pop();

            

            if(grid[i1][j1]==1)

                return abs(i-i1)+abs(j-j1);    

            

            

            for(int k=0;k<4;k++)

            {

                int i2=i1+row[k];

                int j2=j1+col[k];

                if(i2>=0 && j2>=0 && i2<n && j2<m)

                {

                    q.push({i2,j2});

                }

            }

            

        }

    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	     int n=grid.size();

    int m=grid[0].size();

    vector<vector<int>> ans(n,vector<int>(m,0));

    

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            ans[i][j]=distance(i,j,n,m,grid);

        }

    }

    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends