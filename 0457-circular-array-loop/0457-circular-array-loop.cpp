class Solution {
public:
    int nextPosition(vector<int> &nums, int idx, bool &isForward) {
        
        int n=nums.size();
        bool direction= (nums[idx]>=0) ? true : false;

        if(direction != isForward)
            return -1;

        int nextIndex= ((idx+nums[idx])%n+n)%n;

        if(nextIndex==idx)
            return -1;
        
        return nextIndex;

    }
    bool circularArrayLoop(vector<int>& nums) {

        bool isForward;

        for(int i=0; i<nums.size(); i++){
            
            int slow, fast;
            slow=fast=i;

            isForward=(nums[i]>0) ? true: false;

            while(true){
                slow= nextPosition(nums, slow, isForward);
                if(slow==-1)
                    break;
                
                fast= nextPosition(nums, fast, isForward);
                if(fast==-1)
                    break;

                fast= nextPosition(nums, fast, isForward);
                if(fast==-1)
                    break;
                
                if(slow==fast)
                    return true;
            }

        }

        return false;
    }
};