class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++) {
        // skip duplicates
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n - 2; j++) {
            // skip duplicates
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int left = j+1, right = n-1;
            while (left < right) {
                long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // skip duplicates
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left-1]);
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right+1]);
                }
            }
        }
    }
    return res;
}

};
