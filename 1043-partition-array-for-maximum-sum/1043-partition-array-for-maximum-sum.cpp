class Solution {
public:
        int ma(vector<int>& arr, int start, int end) {
        int maximum = INT_MIN;
        for (int i = start; i <= end; i++) {
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }

    int op(vector<int>& arr, int end, int k, int start, vector<int>& dp) {
        if (start >= end) return 0;
        if (dp[start] != -1) return dp[start];

        int maxVal = INT_MIN;
        for (int i = start; i < start + k && i < end; i++) {
            int currentMax = ma(arr, start, i);
            int currVal = (i - start + 1) * currentMax + op(arr, end, k, i + 1, dp);
            maxVal = max(maxVal, currVal);
        }

        return dp[start] = maxVal;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
      vector<int> dp(n, -1);
        return op(arr, n, k, 0, dp);   
    }
};