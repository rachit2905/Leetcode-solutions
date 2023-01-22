class Solution {
public:
    int dir1[4] = {-1,0,1,0};
    int dir2[4] = {0,-1,0,1};

    void dfs(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();

        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        for(int x=0; x<4; x++){ 
            int nrow = i + dir1[x];
            int ncol = j + dir2[x];
            dfs(grid,nrow,ncol);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if((i == 0 || j == 0 || i == row-1 || j == col-1) && grid[i][j] == 0){
                    dfs(grid,i,j);
                }
            }
        }

        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};