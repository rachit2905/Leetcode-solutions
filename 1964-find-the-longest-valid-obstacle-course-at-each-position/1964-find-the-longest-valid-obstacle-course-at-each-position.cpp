class Solution {
public:
    int find(vector<int>&nums,int target){
        int l=0;
        int hi=nums.size()-1;
        int ans=0;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(nums[mid]<=target){
                ans=mid;
                l=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<n;i++){
            if(nums[i]>=temp.back()){
                temp.push_back(nums[i]);
                ans.push_back(temp.size());
            }
            else{
                int ind=upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
                ans.push_back(ind+1);
            }
        }
        return ans;
        
    }
};