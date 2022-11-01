class Solution
{
    public:
        int check(vector<vector < int>> &grid, int row, int col)
        {
            if (col >= grid[0].size() || col < 0) return -1;	
            if (row >= grid.size()) return col;	

            if (grid[row][col] == -1)
            {
                if ((col - 1 > 0) && grid[row][col - 1] == 1) return -1;
                else return check(grid, row + 1, col - 1);
            }
            else
            {
                if (col + 1 < grid[0].size() && grid[row][col + 1] == -1) return -1;
                else return check(grid, row + 1, col + 1);
            }
        }

    vector<int> findBall(vector<vector < int>> &grid)
    {
        vector<int> ans(grid[0].size(), -1);

        for (int j = 0; j < grid[0].size(); j++)
        {
            ans[j] = check(grid, 0, j);
        }

        return ans;
    }
};