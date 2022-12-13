class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(j>0 && j<matrix.size()-1)
                matrix[i+1][j]+=min(matrix[i][j],min(matrix[i][j-1],matrix[i][j+1]));
                else if(j>0)
                    matrix[i+1][j]+=min(matrix[i][j],matrix[i][j-1]);
                else if(j<matrix.size()-1)
                    matrix[i+1][j]+=min(matrix[i][j],matrix[i][j+1]);
            }
        }
      int  ans=INT_MAX;
        for(int i=0;i<matrix.size();i++)
            ans=min(ans,matrix[matrix.size()-1][i]);
        return ans;
    }
};