//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         queue<pair<pair<int,int>,int>>w;
       vector<vector<bool>>vis(N,vector<bool>(M,false));
       w.push({{0,0},0});
       vis[0][0]=true;
       int dx[]={0,0,-1,1};
       int dy[]={-1,1,0,0};
       int res=INT_MAX;
       while(!w.empty())
       {
           int x=w.front().first.first;
           int y=w.front().first.second;
           int steps=w.front().second;
           w.pop();
           if(x==X&&y==Y)
           {
               res=min(res,steps);
           }
           for(int dir=0;dir<4;dir++)
           {
               int nx=x+dx[dir];
               int ny=y+dy[dir];
               if(nx>=0&&nx<N&&ny>=0&&ny<M&&A[nx][ny]!=0&&!vis[nx][ny])
               {
                   vis[nx][ny]=true;
                   w.push({{nx,ny},steps+1});
               }
           }
       }
       return res==INT_MAX?-1:res;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends