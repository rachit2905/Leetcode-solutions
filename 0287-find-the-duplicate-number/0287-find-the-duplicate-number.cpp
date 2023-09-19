class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        //find collision point
        do{
          slow = nums[slow];
          fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];

        //find duplicate number
        //distance of duplicate from stating point is multiple of distance from collision point
        while(fast!=slow)
        {
          fast = nums[fast];
          slow = nums[slow];
        }

        return slow;
    }
};