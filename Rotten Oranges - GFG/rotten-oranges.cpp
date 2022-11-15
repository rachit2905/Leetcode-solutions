//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int ar[4]={0,0,1,-1};
        int br[4]={1,-1,0,0};
        int co=0,n=grid.size(),m=grid[0].size(),res=0,res1=0;
        queue<pair<int,int>>q1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                co++;
                if(grid[i][j]==2)
                q1.push({i,j});
            }
        }
        while(!q1.empty())
        {
           
            int t=q1.size();
            res1+=t;           
            if(res1==co)return res;
            while(t--)
            {
                 pair<int,int>p1;
            p1=q1.front();
            q1.pop();
            int a=p1.first;
            int b=p1.second;

            for(int i=0;i<4;i++)
            {
              int x1=a+ar[i],y1=b+br[i];
              if(x1>=n || x1<0 || y1>=m || y1<0||grid[x1][y1]!=1)continue;
              grid[x1][y1]=2;
              q1.push({x1,y1});
            }
            }
            res++;
        }
        if(res1==co)return res;
        else return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends