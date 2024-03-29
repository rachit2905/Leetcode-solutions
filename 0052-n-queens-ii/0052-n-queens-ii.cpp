class Solution {
public:
     bool isSafe(int row,int col,vector<string> &board,int n){
	
		for(int i=0;i<=col;i++){
			if(board[row][i]=='Q') return false;
		}
		
		int r=row,c=col;
		while(r>=0 && c>=0){
			if(board[r][c]=='Q') return false;
			r--;
            c--;
		}
		r=row;
        c=col;
		while(r<n && c>=0){
			if(board[r][c]=='Q') return false;
			r++;
            c--;
		}
		return true;
	}

    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(col == n){
			 ans.push_back(board);
			 return ;
		 }

        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
      vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');

        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);

        return ans.size();   
    }
};