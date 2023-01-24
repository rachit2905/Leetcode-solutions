class Solution {
public:
     void dfs(int i, int j, int rows,int cols, vector<vector<int>>& grid2,vector<vector<int>>& grid1, int& flag){

        //Boundary Conditions
        if(i<0||i>=rows||j<0||j>=cols||grid2[i][j]!=1) return ;
        // checking that the grid1 is also having the corresponding land cell or not
        if(grid2[i][j] == 1){
           if(grid1[i][j] == 0){
               flag = 0;
               return;
           }
           // changing the value so that it will not visit again
           grid2[i][j] = 2;

       }
        dfs(i+1,j,rows,cols,grid2,grid1,flag);
        dfs(i-1,j,rows,cols,grid2,grid1,flag);
        dfs(i,j+1,rows,cols,grid2,grid1,flag);
        dfs(i,j-1,rows,cols,grid2,grid1,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        int count=0;
       
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid2[i][j] == 1){
                    int flag = 1;
                    dfs(i,j,rows,cols,grid2,grid1,flag);
                    if(flag == 1)
                      count++;
                }
            }
        }
        return count;
        
    }
};