class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            vector<char> ans;
           	//ans.push_back(chars[0]);
            int co = 1;
            if (chars.size() == 1)
            {
                return 1;
            }
            for (int i = 1; i < chars.size(); i++)
            {
                if (chars[i - 1] != chars[i])
                {
                    if (i == 1)
                    {
                        ans.push_back(chars[0]);
                       	//ans.push_back(1);
                        continue;
                    }
                    else
                    {
                        ans.push_back(chars[i - 1]);
                        if (co == 1) continue;
                        string s1 = to_string(co);
                        for (auto it: s1)
                        {
                            ans.push_back(it);
                        }
                        co = 1;
                        continue;
                    }
                }
                else
                    co++;
            }
            if (chars.size() > 1)
            {
                ans.push_back(chars[chars.size() - 1]);
                if (co > 1)
                {
                    string s1 = to_string(co);
                    for (auto it: s1)
                    {
                        ans.push_back(it);
                    }
                }
            }
            for (auto it: ans)
            {
                cout << it;
            }
            chars = ans;
            return (int) ans.size();
        }
};