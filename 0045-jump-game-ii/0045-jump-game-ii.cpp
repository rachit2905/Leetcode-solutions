class Solution {
public:
    int jump(vector<int>& arr) {
       int n = arr.size();
        vector<int> dp(n+1, -1);
        dp[n-1] = 0;

        for(int index = n-2; index>=0 ; index--)
        {
            int minStep = 1e9;
            int jump = arr[index];
            for(int i=1; i<= jump; i++)
            {
                if(index + i <= n-1)
                {
                    int curr = 1 + dp[index+i];
                    minStep = min(minStep, curr);
                }
            } 

            dp[index] = minStep;
        }
        
        return dp[0];
        
    }
};