class Solution {
public:
    int findInLeft(vector<int>a, int target){
        int low=0,high=a.size()-1,result=-1;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(a[mid]==target){
                result = mid;
                high=mid-1;
            }else if(a[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return result;
    }
    int findInRight(vector<int>a, int target){
        int low=0,high=a.size()-1,result=-1;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(a[mid]==target){
                result = mid;
                low=mid+1;
            }else if(a[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findInLeft(nums, target);
        int right = findInRight(nums, target);
        return {left, right};
    }
};