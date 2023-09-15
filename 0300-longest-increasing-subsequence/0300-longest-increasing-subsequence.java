class Solution {
    public int lengthOfLIS(int[] nums) {
               int[] dp = new int[nums.length];
        //considering max=1 as each index value in itself is a sunsequence of array
        int max = 1;

        //outer loop for actual array
        for(int i=0;i<nums.length;i++){
            //initializing base LIS at index
            dp[i] = 1;
            //checking from 0 to <i 
            for(int j=0;j<i;j++){
                //if number is < currValue of nums[i]
                if(nums[j]<nums[i]){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                    max = Math.max(max,dp[i]);
                }
            }
        }
        return max;
    }
}