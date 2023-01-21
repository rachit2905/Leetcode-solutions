class Solution {
public:
    int dfs(int index,vector<vector<int>>& stones,int n,vector<int>&visi)
    {
        visi[index]=1;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(!visi[i] &&(stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1]))
                res+=
                (dfs(i,stones,n,visi)+1);
        }
        return res;
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>visi(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visi[i])continue;
            cnt+=(dfs(i,stones,n,visi));
        }
        return cnt;
    }
};