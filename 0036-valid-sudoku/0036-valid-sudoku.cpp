class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            bool co = true, co1 = true, co2 = true;
            for (int i = 0; i < 9; i++)
            {
                vector<int> v1(9, 0);
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int x = board[i][j] - '0' - 1;
                        if (v1[x] != 0)
                        {
                            return false;
                        }
                        else
                            v1[x]++;
                    }
                }
            }
            for (int i = 0; i < 9; i++)
            {
                vector<int> v1(9, 0);
                for (int j = 0; j < 9; j++)
                {
                    if (board[j][i] != '.')
                    {
                        int x = board[j][i] - '0' - 1;
                        if (v1[x] != 0)
                        {
                            return false;
                        }
                        else
                            v1[x]++;
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int it = 0; it < 3; ++it)
                {

                    unordered_map<char, int> m;
                    for (int j = i * 3; j < i *3 + 3; ++j)
                    {
                        for (int k = it * 3; k < it *3 + 3; ++k)
                        {
                            if (board[j][k] == '.') continue;
                            if (m[board[j][k]])
                            {
                                return false;
                            }
                            m[board[j][k]] = 1;
                        }
                    }
                }
            }

            return true;
        }
};