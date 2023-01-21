class Solution {
public:
   bool isvalid(int i,int j,int n){
         return i >= 0 && j >= 0 && i<n && j<n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])q.push({i,j}),vis[i][j]=1;
            }
        }
        int qsize = q.size();
        int len = -1;
        int dir[] = {0,1,0,-1,0};
        while(!q.empty()){
            len++;
            while(qsize--){
                pair<int,int>  p = q.front();q.pop();
                int i = p.first;
                int j = p.second;
                for(int k=0;k<4;k++){
                    int r = i + dir[k];
                    int c = j + dir[k+1];
                    if(isvalid(r,c,n) && !vis[r][c]){
                             vis[r][c] = 1;
                             q.push({r,c});
                    }
                }
            }
            qsize = q.size();
        }
        return len > 0 ? len : -1;
    }
};