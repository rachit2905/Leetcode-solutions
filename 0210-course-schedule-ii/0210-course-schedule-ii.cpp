class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int>adj[num];
        for(int i=0;i<pre.size();i++)
        {
            int x=pre[i][0];
            int y=pre[i][1];
            adj[y].push_back(x);
            
        }
        vector<int>ind(num,0);
        for(int i=0;i<num;i++)
        {
            for(auto it:adj[i])
            {
                ind[it]++;
            }
        }
        queue<int>q1;
        for(int i=0;i<num;i++)
        {
            if(ind[i]==0)
                q1.push(i);
            
        }
        vector<int>ans;
        while(!q1.empty())
        {
            int x=q1.front();
            q1.pop();
            ans.push_back(x);
            for(auto it:adj[x])
            {
                ind[it]--;
                if(ind[it]==0)
                {
                    q1.push(it);
                }
                
            }
        }
        if(ans.size()!=num)
            return {};
        else return ans;
    }
};