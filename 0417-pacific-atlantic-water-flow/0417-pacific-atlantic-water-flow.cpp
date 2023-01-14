class Solution
{
    public:
        void dfs(int sr, int sc, vector<vector < int>> &heights, vector< vector< int>> &visited)
        {
            visited[sr][sc] = 1;
            int n = heights.size();
            int m = heights[0].size();
            int dr[] = { -1,
                0,
                +1,
                0
            };
            int dc[] = { 0,
                -1,
                0,
                +1
            };
            for (int i = 0; i < 4; i++)
            {
                int nrow = dr[i] + sr;
                int ncol = dc[i] + sc;
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol] && heights[nrow][ncol] >= heights[sr][sc])
                {
                    dfs(nrow, ncol, heights, visited);
                }
            }
        }
    vector<vector < int>> pacificAtlantic(vector<vector < int>> &heights)
    {
       	//at i,j+1 && i+1,j
       	//pc i-1,j && i,j-1 
        int n = heights.size();
        int m = heights[0].size();
        vector<vector < int>> ans;
        vector<vector < int>> visited1(n, vector<int> (m, 0)), visited2(n, vector<int> (m, 0));
        int dr[] = { -1,
            0,
            +1,
            0
        };
        int dc[] = { 0,
            -1,
            0,
            +1
        };
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, heights, visited1);
        }
        for (int j = 0; j < m; j++)
        {
            dfs(0, j, heights, visited1);
        }
        for (int j = 0; j < m; j++)
        {
            dfs(n - 1, j, heights, visited2);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i, m - 1, heights, visited2);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited1[i][j] == 1 && visited2[i][j] == 1)
                {
                    ans.push_back({ i,
                        j });
                }
            }
        }
        return ans;
    }
};