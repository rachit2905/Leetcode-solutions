class Solution {
public:
     const int MOD = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
       

        sort(nums.begin(),nums.end());

        int left=0, right=nums.size()-1,count=0;

        vector<int> pow2(nums.size()+1,1);

        for(int i=1; i<=nums.size(); i++)

         pow2[i]=(2*pow2[i-1])% MOD ;

        while(left <= right){

            if(nums[right]+nums[left] <= target){

                
                count = (count + pow2[right - left]) % MOD ;
                left++;
            }
            else{
                right--;
            }
         }
         return count;
    }
};