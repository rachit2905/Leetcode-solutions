class Solution
{
    public:
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            if(grid[0][0]==1)return -1;
            queue<pair<int, int>> q1;
            q1.push({ 0,
                0 });
        
            int ans = 0;
            int dirx[] = { 0,
                0,
                1,
                1,
                -1,
                -1,
                1,
                -1
            };
            int diry[] = { 1,
                -1,
                0,
                1,
                0,
                -1,
                -1,
                1
            };
            vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
           vis[0][0]=1;
            int n=grid.size();
            while (!q1.empty())
            {
                int sz = q1.size();
                for (int i = 0; i < sz; i++)
                {
                    auto it = q1.front();
                    q1.pop();
                    int x = it.first;
                    int y = it.second;
                    if (x == n - 1 && y == n - 1) return ans+1;
                    for (int j = 0; j < 8; j++)
                    {
                        int x1 = x + dirx[j];
                        int y1 = y + diry[j];
                        if (x1 < 0 || y1 < 0 || x1 >= grid.size() || y1 >= grid[0].size() || vis[x1][y1] || grid[x1][y1] == 1)
                            continue;
                        vis[x1][y1] = 1;
                        q1.push({ x1,
                            y1 });
                    }
                }
                ans++;
            }
            return -1;
        }
};