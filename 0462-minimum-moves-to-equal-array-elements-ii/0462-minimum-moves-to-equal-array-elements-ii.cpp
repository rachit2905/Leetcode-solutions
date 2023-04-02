class Solution {
public:
    int minMoves2(vector<int>& nums) {
           sort(nums.begin(),nums.end());
        int middle=nums.size()/2;
        int sum=0;
        int x=nums[middle];
        for(int i=0;i<nums.size();i++)
        {
            sum+=abs(nums[i]-x);
        }
        return sum;
    }
};