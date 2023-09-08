class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int co=-1;
       for(int i=nums.size()-2;i>=0;i--)
       {
           if(nums[i]<nums[i+1]){
               co=i;break;
           }
       }
        if(co==-1){
            sort(nums.begin(),nums.end());
        }
        else
        {
            int x=INT_MAX,in=-1;
            for(int j=co;j<nums.size();j++)
            {
                if(nums[j]>nums[co])
                {
                x=min(x,nums[j]);
                    in=j;
                }
            }
            if(in!=-1)
            swap(nums[co],nums[in]);
            reverse(nums.begin()+co+1,nums.end());
        }
    }
};