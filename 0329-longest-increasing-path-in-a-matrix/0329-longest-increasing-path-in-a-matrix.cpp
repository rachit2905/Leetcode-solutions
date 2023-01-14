class Solution
{
    public:
        int dp[201][201];
    int solve(int x, int y, vector<vector < int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int cnt = 1;
        if (dp[x][y] != -1) return dp[x][y];
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y]) cnt = max(cnt, 1 + solve(x - 1, y, matrix));

        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y]) cnt = max(cnt, 1 + solve(x, y - 1, matrix));

        if (x + 1 < m && matrix[x + 1][y] > matrix[x][y]) cnt = max(cnt, 1 + solve(x + 1, y, matrix));

        if (y + 1 < n && matrix[x][y + 1] > matrix[x][y]) cnt = max(cnt, 1 + solve(x, y + 1, matrix));
        return dp[x][y] = cnt;
    }
    int longestIncreasingPath(vector<vector < int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int res = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = max(res, solve(i, j, matrix));
            }
        }

        return res;
    }
};