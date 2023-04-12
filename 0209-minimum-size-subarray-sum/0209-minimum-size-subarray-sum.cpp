class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
           int sz=INT_MAX,i=0,su=0;
            for(int j=0;j<nums.size();j++)
            {
                su+=nums[j];
                while(su>=target)
                {
                    sz=min(sz,j-i+1);
                    su-=nums[i++];
                }
            }
            if(sz!=INT_MAX)
            return sz;
            else return 0;
        }
};