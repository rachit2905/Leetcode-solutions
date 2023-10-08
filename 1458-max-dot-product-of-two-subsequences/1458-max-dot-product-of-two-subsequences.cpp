class Solution {
public:
     int solve(int ind1, int ind2, int f, vector<int> &nums1, vector<int> &nums2, vector<vector<vector<int>>> &dp)
{
    if (ind1 == nums1.size() or ind2 == nums2.size())
    {
        if (f)
        {
            return 0;
        }
        return -1e9;
    }

    if (dp[ind1][ind2][f] != -1)
    {
        return dp[ind1][ind2][f];
    }

    int opt1 = nums1[ind1] * nums2[ind2] + solve(ind1 + 1, ind2 + 1, 1, nums1, nums2, dp);
    int opt2 = solve(ind1 + 1, ind2, f, nums1, nums2, dp);
    int opt3 = solve(ind1, ind2 + 1, f, nums1, nums2, dp);
    int opt4 = solve(ind1 + 1, ind2 + 1, f, nums1, nums2, dp);

    return dp[ind1][ind2][f] = max({opt1, opt2, opt3, opt4});
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<vector<int>>> dp(nums1.size() + 1, vector<vector<int>>(nums2.size() + 1, vector<int>(2, -1)));
    return solve(0, 0, 0, nums1, nums2, dp);
}
};