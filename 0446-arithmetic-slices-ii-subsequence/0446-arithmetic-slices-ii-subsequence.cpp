class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         vector<unordered_map<long long,int>> dp(nums.size());
        int sum = 0;
        long long diff;
        int prev;
        for(int i = 0; i < nums.size(); i++){
           // dp[i].reserve(n+1);
            for(int j = 0; j < i; j++){
                diff = (long long)nums[i]- (long long) nums[j];
                prev = dp[j][diff];
                dp[i][diff] += prev+1;
                sum += prev;
            }
        }
        return sum;
    }
};