class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
         vector<int> DP(target + 1, 0);
    DP[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= 0; j--) {
            DP[j] = 0;
            for (int x = 1; x <= k; x++) {
                if (x <= j)
                    DP[j] = (DP[j] + DP[j - x]) % (int)(1e9 + 7);
            }
        }
    }
    return DP[target];
    }
};