class Solution {
public:
    void help(int x,int y,vector<vector<char>>& board,int m,int n,  vector<vector<int>>&vis)
    {
        if(x>m-1 || x<0 || y<0 || y>n-1)return;
         if(board[x][y]=='X' || vis[x][y])
            return;
        vis[x][y]=1;
        help(x+1,y,board,m,n,vis);
        help(x-1,y,board,m,n,vis);
        help(x,y+1,board,m,n,vis);
        help(x,y-1,board,m,n,vis);
        
        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')help(i,0,board,m,n,vis);
            if(!vis[i][n-1] && board[i][n-1]=='O')help(i,n-1,board,m,n,vis);
        }
         for(int i=0;i<n;i++)
        {
            if(!vis[0][i] && board[0][i]=='O')help(0,i,board,m,n,vis);
            if(!vis[m-1][i] && board[m-1][i]=='O')help(m-1,i,board,m,n,vis);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};