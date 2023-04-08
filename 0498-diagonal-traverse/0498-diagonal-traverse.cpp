class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int k=m*n;
        int row=0,col=0;
        int x=0;
        vector<int> ans;
        while(row<n && col<m && col>=0 && row>=0 && k--)
        {
            if(x%2==0)
            {
                //up
                ans.push_back(mat[row][col]);
                row--;col++;
                if(col==m)
                {
                    row+=2;col--;x++;
                }
                if(row<0)
                {
                    row++;x++;
                }
                
            }
            else{
                //down
                ans.push_back(mat[row][col]);
                row++;col--;
                if(row==n)
                {
                    col+=2;row--;x++;
                }
                if(col<0)
                {
                    col++;x++;
                }
            }
        }
        return ans;
    }
};