class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>ans;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                    ans.push_back({i,j});
            }
        }
        for(auto it:ans)
        {
            int row=it.first;
            int col=it.second;
            for(int i=0;i<matrix[0].size();i++)
                matrix[row][i]=0;
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][col]=0;
            }
        }
    }
};