class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(i<n)
        {
            int j=nums[i]-1;
            if(nums[i]!=nums[j])
                swap(nums[i],nums[j]);
            else i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return nums[i];
        }
      return -1;  
    }
};