class Solution {
public:
    int solve(int node,vector<int> &ans,vector<int> &edges){
        if(ans[node]!=-1)return ans[node];
        else return ans[node]=1+solve(edges[node],ans,edges);
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int> indeg(n,0);
        for(auto it:edges){
            indeg[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> vis(n,-1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            indeg[edges[node]]--;
            if(indeg[edges[node]]==0){
                q.push(edges[node]);
            }
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
               int node=i,cnt=1;
               while(edges[node]!=i){
                   cnt++;
                   node=edges[node];
               }
               node=i;
               ans[i]=cnt;
               vis[i]=1;
               while(edges[node]!=i){
                   node=edges[node];
                   vis[node]=1;
                   ans[node]=cnt;
               }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                solve(i,ans,edges);
            }
        }
        return ans;
    }
};