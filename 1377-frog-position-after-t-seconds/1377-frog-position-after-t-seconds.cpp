class Solution {
public:
    void dfs(vector<int>&path,vector<vector<int>>&tree,int src,int par,int target){
    if(src==target){
        path.push_back(target);
        return;
    }
    for(auto x:tree[src]){
        if(x!=par)
            dfs(path,tree,x,src,target);
            if(!path.empty()){
                path.push_back(src);
                return;
            }
    } 
}

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1;
        double res=1.0;
        vector<vector<int>>tree(n+1);
        vector<int>path;
        for(auto&x:edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        dfs(path,tree,1,-1,target);
        int req=path.size()-1;
       // cout<<req<<"\n";
        if(t<req) return 0;
        if(t>req && ((target==1 && tree[target].size()) || (target!=1 && tree[target].size()!=1))) return 0;
        for(int i=1;i<path.size();i++){
            double x=tree[path[i]].size()-(path[i]!=1);
            res=res*(1.0/x);
        }
        return res;
    }
};