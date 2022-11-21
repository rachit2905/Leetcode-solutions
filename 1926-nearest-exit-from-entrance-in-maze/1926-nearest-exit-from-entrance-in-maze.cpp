class Solution
{
    public:
        int nearestExit(vector<vector < char>> &m, vector< int > &e)
        {
            queue<pair<int, int>> q1;
            q1.push({ e[0],
                e[1] });
            int moves = 1;
            int x[] = { 1,
                -1,
                0,
                0
            };
            int y[] = { 0,
                0,
                1,
                -1
            };
              m[e[0]][e[1]] = '+';
            while (!q1.empty())
            {

                int sz = q1.size();
                for (int k = 0; k < sz; k++)
                {
                    auto it = q1.front();
                    q1.pop();
                  
                    for (int i = 0; i < 4; i++)
                    {
                        int x1 = it.first + x[i];
                        int y1 = it.second + y[i];
                        if(x1<0 || y1<0 || x1>=m.size()|| y1>=m[0].size() || m[x1][y1]=='+')continue;
                        if (x1 == 0 || y1 == 0 || y1 == m[0].size() - 1 || x1 == m.size() - 1 && m[x1][y1] != '+')
                            return moves;
                        
                            m[x1][y1] = '+';
                            q1.push({ x1,
                                y1 });
                        
                    }
                }
                moves++;
            }
            return -1;
        }
};