class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {
            string g = "ACGT";
            queue<pair<string, int>> q;
            q.push(make_pair(start, 0));
            map<string, int> m;
            m[start] = 1;
            int siz = (int) bank.size();
            while (!q.empty())
            {
                pair<string, int> front = q.front();
                q.pop();
                if (front.first == end) return front.second;

                for (int i = 0; i < 8; ++i)
                {
                    string tmp = front.first;
                    for (int k = 0; k < 4; ++k)
                    {
                        tmp[i] = g[k];
                        if (!m.count(tmp))
                        {
                            for (int j = 0; j < siz; ++j)
                            {
                                if (tmp == bank[j])
                                {
                                    q.push(make_pair(tmp, front.second + 1));
                                    m[tmp] = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return -1;
        }
};