class Solution
{
    public:
        int minDeletionSize(vector<string> &strs)
        {
            int co = 0;
            for (int j = 0; j < strs[0].size(); j++)
            {
                string s1 = "";
                for (int i = 0; i < strs.size(); i++)
                {
                    s1 += strs[i][j];
                }
                string s2 = s1;
                sort(s2.begin(), s2.end());
                if (s2 != s1)
                {
                    co++;
                }
            }
            return co;
        }
};