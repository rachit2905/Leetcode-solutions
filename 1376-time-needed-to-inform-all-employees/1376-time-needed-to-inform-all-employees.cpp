class Solution {
public:
    void sumi(int node, int time, int &ans, vector<pair<int,int>> adj[]){
    if(adj[node].size()==0) ans=max(time,ans);
    for(auto child:adj[node]){
        sumi(child.first,time+child.second,ans,adj);
    }
}

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adj[manager[i]].push_back({i,informTime[manager[i]]});
        } 
        int ans=0;
        int time=0;
        sumi(headID,time,ans,adj);
        return ans;
    }
};
