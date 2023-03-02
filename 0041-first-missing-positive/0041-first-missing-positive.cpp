class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x=1;
        sort(nums.begin(),nums.end());
        for(auto it:nums)
        {
            if(it>0 && it>x)
                continue;
            else if(it>0 && it==x)
            {
                x++;
            }
        }
        return x;
    }
};