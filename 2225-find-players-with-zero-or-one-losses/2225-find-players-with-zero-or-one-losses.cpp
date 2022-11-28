class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>m1,m2;
        for(auto it:matches)
        {
            m1[it[0]]++,m2[it[1]]++;
            
        }
        vector<vector<int>>ans(2);
        for(auto it:m1)
        {
            if(m2[it.first]==0)
                ans[0].push_back(it.first);
        }
        for(auto it:m2)
        {
            if(m2[it.first]==1)
                ans[1].push_back(it.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};