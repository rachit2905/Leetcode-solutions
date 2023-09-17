class Solution {
public:
    int countWays(vector<int>& nums) {
         int res = 0, n = nums.size();
        vector<int> cnt(n + 1);
        
        for(auto& num: nums) 
            cnt[num]++;
        
        int selected = 0;
        for(int i = 0; i <= n; i++) {
            if(cnt[i] != 0) {
                selected += cnt[i];
                continue;
            }
            if(selected == i)
                res++;
        }
        return res;
    }
};