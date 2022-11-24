class Solution
{
    public:
        bool dfs(int i, int j, int m, int n, vector<vector < char>> &board, string word, int k)
        {
            if (i < 0 || j < 0 || i >= m || j >= n)
            {
                return false;
            }

            if (board[i][j] == word.at(k))
            {
                char temp = board[i][j];
                board[i][j] = '#';
                if (k == word.length() - 1)
                {
                    return true;
                }
                else if (dfs(i + 1, j, m, n, board, word, k + 1) ||
                    dfs(i - 1, j, m, n, board, word, k + 1) ||
                    dfs(i, j + 1, m, n, board, word, k + 1) ||
                    dfs(i, j - 1, m, n, board, word, k + 1))
                    return true;

                board[i][j] = temp;
            }
            return false;
        }

    bool exist(vector<vector < char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector < bool>> visited(m, vector<bool> (n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (dfs(i, j, m, n, board, word, 0)) return true;
            }
        }
        return false;
    }
};