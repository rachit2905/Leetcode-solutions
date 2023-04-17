class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int n = 1;
        if(nums[0]!=1)
            return 1;
        int i;
        int idx=1;
        for(i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]!=(1<<idx)){
                if((nums[i] & nums[i-1]) != 0)
                    continue;
                return (1<<idx);
            }
            if(nums[i]==(1<<idx)){
                idx++;
            }
        }
        return (1<<idx); 
    }
};