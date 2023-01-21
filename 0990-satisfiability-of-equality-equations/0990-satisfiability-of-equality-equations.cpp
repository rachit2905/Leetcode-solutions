class Solution {
public:
    vector<int>parent;
    int findp(int a)
    {
        if(a==parent[a])return a;
        else return findp(parent[a]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        int n=equations.size();
        for(int i=0;i<26;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
            {
                int x=findp(equations[i][0]-'a');
                int y=findp(equations[i][3]-'a');
                if(x!=y)
                {
                    parent[y]=x;
                } 
            }
        }
         for (int i = 0; i < n; i++) {
            if (equations[i][1] == '!') {
                int x = findp(equations[i][0]-'a');
                int y = findp(equations[i][3]-'a');
                if (x == y)
                    return false;
            }
         }
        return 1;
    }
};