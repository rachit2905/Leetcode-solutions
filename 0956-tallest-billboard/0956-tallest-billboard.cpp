class Solution
{
   int height(int i,int j,vector<int>& rods,unordered_map<int,unordered_map<int,int>>& mp){
        int n=rods.size();
        if(i==n){
            if(j==0)return 0;//diff is zero return 
            return INT_MIN;
        }
        if(mp[i].find(j)!=mp[i].end())return mp[i][j];
        //options
        int ans=INT_MIN;
        //ignoring the rod
        ans=height(i+1,j,rods,mp);
        //adding rod in group1 => add rods[i] to result
        ans=max(ans,rods[i]+height(i+1,j+rods[i],rods,mp));
         //adding rod in group2 
        ans=max(ans,height(i+1,j-rods[i],rods,mp));
        return mp[i][j]=ans;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,unordered_map<int,int>>mp;
        return height(0,0,rods,mp);
    }
};