class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         long long int sum=0;
     int cnt=0;
     for(int i=0;i<nums.size();i++){
         if(sum+nums[i]<=x){
             sum+=1LL*nums[i];
             cnt++;
         }else{
             break;
         }

     }
     long long int ans=INT_MAX;
     if(sum==x){
         ans=cnt;
     }

     cnt--;
     for(int j=nums.size()-1;j>cnt;j--){
         sum+=nums[j];
         while(sum>x && cnt>=0){
             sum-=1LL*nums[cnt];
             cnt--;
         }
         if(sum==x){
             long long int ans2=(cnt+1+nums.size()-j);
             ans=min(ans,ans2);
         }else if(sum>x){
             break;
         }
     }
     if(ans==INT_MAX){
         return -1;
     }
return ans;
    }
};