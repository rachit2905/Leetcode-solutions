class Solution {
public:
     bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; 
            sum%=k;    //i=0 : sum=5 mpp[5]=0
            if(sum==0 && i) return true;
                //corner condition [0,0] & k=0 then true;
                
            if(mpp.find(sum)!=mpp.end()){
                //i=1 : sum=(5+2)%k=1  mpp[1]=1;
                //i=2 : sum=(1+4)%k=1  mpp[5] this is present;
                // 2-mpp[5]>1 count number of time 5 is present
                // if more than 1 then true;
                //then ok
                if(i-mpp[sum]>1)return true;
            }
            else mpp[sum]=i;
        }
        return false;
    }
};