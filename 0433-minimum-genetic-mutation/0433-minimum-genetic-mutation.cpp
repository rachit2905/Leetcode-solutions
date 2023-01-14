class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),end)==bank.end())return -1;
        queue<string>q1;
        map<string,bool>vis;
        for(auto it:bank)
        {
            vis.insert({it,0});
        }
        q1.push(start);
        vis.insert({start,1});
        char ar[]={'A','T','C','G'};
        int steps=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            for(int i=0;i<sz;i++)
            {
                string temp=q1.front();
                string temp1=temp;
                q1.pop();
                if(temp==end)return steps;
                for(int i=0;i<temp.length();i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        temp=temp1;
                        if(ar[j]!=temp[i])
                        {
                            temp[i]=ar[j];
                            if(find(bank.begin(),bank.end(),temp)!=bank.end() && vis[temp]==0)
                            {
                                q1.push(temp);
                                vis[temp]=1;
                            }
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};