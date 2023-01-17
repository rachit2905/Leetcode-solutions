class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int _find(int x)
    {
        if(par[x]==x)
            return x;
        else return par[x]=_find(par[x]);
    }
    void _union(int x,int y)
    {
        int u=_find(x);
        int v=_find(y);
        if(rank[u]>rank[v])
        {
            par[v]=u;
        }
        else if(rank[v]>rank[u])
        {
            par[u]=v;
        }
        else
        {
            par[v]=u;
        rank[u]++;
        }
        
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        par.resize(n+1);
        rank.resize(n+1);
         for(int i = 0; i<row.size(); i++)
       {
           par[i] = i; 
           rank[i] = 1;
       }
        for(int i=0;i<n;i+=2)
        {
            _union(row[i],row[i+1]);
        }
        int cnt=0;
        for(int i=0;i<n;i+=2)
        {
            int a=_find(i);
            int b=_find(i+1);
            if(a!=b)
            {
                cnt++;
                _union(a,b);
            }
        }
        return cnt;
    }
};