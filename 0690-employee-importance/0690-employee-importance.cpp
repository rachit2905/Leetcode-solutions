/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id,vector<int>adj[],int &ans,vector<int>&imp,vector<int>&vis)    
    {
        vis[id]=1;
        ans+=imp[id];
        for(auto it:adj[id])
        {
            if(!vis[it])
            {
                dfs(it,adj,ans,imp,vis);
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        vector<int>adj[2001];
        vector<int>imp(2001,0);
        vector<int>vis(2001,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            auto it=employees[i];
            imp[it->id]=it->importance;
            //ans+=it->importance;
            for(int j=0;j<it->subordinates.size();j++)
            {
                adj[it->id].push_back(it->subordinates[j]);
            }
        }
        dfs(id,adj,ans,imp,vis);
        return ans;
    }
};