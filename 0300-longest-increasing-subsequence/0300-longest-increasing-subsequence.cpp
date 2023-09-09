class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
      int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int prev_ind=i-1;prev_ind>=-1;prev_ind--){
                int taking=0;
                int nottaking=0;
                if(prev_ind==-1 || nums[i]>nums[prev_ind]){
                    taking=dp[i+1][i+1]+1;
                }
                nottaking=dp[i+1][prev_ind+1];

                dp[i][prev_ind+1]=max(taking,nottaking);
            }
        }
        
        return dp[0][0];
        
    }
};