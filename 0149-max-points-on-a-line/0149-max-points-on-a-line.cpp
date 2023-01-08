class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
         int n=v.size(),ans=1;
        for(int i=0;i<n;i++)
        {
            unordered_map<long double,int> mp;
            long double sl;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;  //not storing in map for same point
					
                if(v[j][0]-v[i][0]==0)
                {
                    sl = INT_MAX;  //otherwise the slope will be undefined
                }
                else
                {
                    sl= (v[j][1]-v[i][1])/( (v[j][0]-v[i][0]) * 1.0 );  //calculating slope and making it in double
                }
                mp[sl]++;
            }
            for(auto it : mp)
            {
                ans=max(ans,it.second+1);  //storing max points in one slope
            }
        }
        return ans;
    }
};