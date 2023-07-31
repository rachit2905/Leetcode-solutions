class Solution
{
    public:
        int help(vector<int> &nums, int target, int sum, int total, vector<vector< int>> &dp, int index)
        {
            if (index == nums.size())
            {
                if (sum == target) return 1;
                else return 0;
            }
            if (dp[index][sum + total] != -1) return dp[index][sum + total];
            int add = help(nums, target, sum + nums[index], total, dp, index + 1);
            int sub = help(nums, target, sum - nums[index], total, dp, index + 1);
            return dp[index][sum + total] = add + sub;
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = 0;
        for (auto it: nums) total += it;
        if (target > total || target<-total) return 0;
        vector<vector < int>> dp(nums.size(), vector<int> (2 *total + 1, 0));
        dp[0][nums[0] + total] = 1;
        dp[0][-nums[0] + total] += 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = -total; j <= total; j++) {
                if(dp[i-1][j+total]>0)
                {
                    int add=j+nums[i];
                    int sub=j-nums[i];
                    dp[i][total+add]+=dp[i-1][j+total];
                    dp[i][total+sub]+=dp[i-1][j+total];
                }
                
            }
        }
        return dp[nums.size()-1][target+total];
    }
};