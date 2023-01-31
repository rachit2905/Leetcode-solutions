class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
     int  n = scores.size();
   int ans = 0;
   vector<pair<int,int>> v;
   for(int i=0;i<scores.size();i++){
   		v.push_back(make_pair(ages[i],scores[i]));
   		
   }
   sort(v.begin(), v.end());
   vector<int> dp(n);
   for(int i=0;i<n;i++){
   	 dp[i] = v[i].second;
   }
   for(int i=0;i<n;i++){
   	for(int j=0;j<i;j++){
   		if(v[j].second<=v[i].second){
            dp[i] = max(dp[i],v[i].second+ dp[j]);
        }
   	}
   	ans = max(ans,dp[i]);
   }
   return ans;   
    }
};