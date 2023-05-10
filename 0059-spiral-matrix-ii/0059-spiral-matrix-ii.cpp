class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
          vector<vector<int>> matrix(n,vector<int>(n));
        if(n==0) return matrix;
        int left=0,top=0,v=1;
        int right=n-1,bottom=n-1;
        while(left<=right && top<=bottom)
        {
            //left to right
            for(int i=left;i<=right;i++)
            {
             matrix[left][i]=v;
             v++;
            }
             top++;

            //top to bottom
            for(int i=top;i<=bottom;i++)
            {
            matrix[i][right]=v;
            v++;
            }
            right--;

            //right to left
            if(top<=bottom) //for single row
            {
            for(int i=right;i>=left;i--)
            {
            matrix[bottom][i]=v;
            v++;
            }
            bottom--;
           }

            // bottom to top
            if(left<=right) //for single column
            {
            for(int i=bottom;i>=top;i--)
            {
            matrix[i][left]=v;
            v++;
            }
            left++;
           }
        }
       return matrix;
    }
};