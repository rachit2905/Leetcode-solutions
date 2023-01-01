class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            vector<string> v1;
            string s1 = "";
            for (auto it: s)
            {
                if (it != ' ')
                    s1 += it;
                else
                {
                    v1.push_back(s1);
                    s1 = "";
                }
            }
            v1.push_back(s1);
            
   	//cout<<v1.size();
         //   cout<<pattern;
            if(v1.size()!=pattern.length())return 0;
    map<char, string> m1;map<string,int>m2;
            for(auto it:v1)
            {
                m2.insert({it,0});
            }
    for (int i = 0; i < pattern.length(); i++)
    {
        if (m1.find(pattern[i]) == m1.end() && m2[v1[i]]==0)
        {
            m1.insert({ pattern[i],
                v1[i] });
        m2[v1[i]]=1;}
        else if (m1[pattern[i]] != v1[i] || (m2[v1[i]]==1 && m1.find(pattern[i]) == m1.end())) return 0;
    }
    return 1;
}
};