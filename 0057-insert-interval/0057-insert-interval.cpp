class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) 
    {
       in.push_back(ni);
        sort(in.begin(),in.end());
        stack<vector<int>>s1;
        s1.push(in[0]);
        for(int i=1;i<in.size();i++)
        {
            auto it=s1.top();
            if(it[1]<in[i][0])
            {
                s1.push(in[i]);
            }
            else if(it[1]<in[i][1])
            {
                it[1]=in[i][1];
                s1.pop();
                s1.push(it);
            }
        }
        in.clear();
        while(!s1.empty())
        {
            in.push_back(s1.top());
            s1.pop();
        }
        sort(in.begin(),in.end());
        return in;
    }
};