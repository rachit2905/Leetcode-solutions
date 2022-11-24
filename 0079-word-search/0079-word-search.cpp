class Solution
{
    public:
        void getStartIdx(vector<vector<char>>& board,char ch,vector<pair<int,int>>& start){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==ch) start.push_back({i,j});
            }
        }
    }
    bool checkIfWordExist(vector<vector<char>>& board,string &word,int idx,int row,int col){
        bool ans;
        if(idx==word.size()) return true;
        if(row>=board.size()||col>=board[0].size()||row<0||col<0||board[row][col]!=word[idx]) return false;
        board[row][col] = '-';
        ans = checkIfWordExist(board,word,idx+1,row+1,col) || checkIfWordExist(board,word,idx+1,row-1,col) ||checkIfWordExist(board,word,idx+1,row,col+1) || checkIfWordExist(board,word,idx+1,row,col-1);
        board[row][col] = word[idx];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> start;
        getStartIdx(board,word[0],start);
        for(pair<int,int> startIdx:start){
            int row = startIdx.first;
            int col = startIdx.second;
            if(checkIfWordExist(board,word,0,row,col)) return true;
        }
        return false;
    }
};