class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            int j=nums[i];
            if(nums[i]<nums.size() && nums[i]!=nums[j])swap(nums[i],nums[j]);
            else
            i++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)return i;
        }
        return nums.size();
    }
};