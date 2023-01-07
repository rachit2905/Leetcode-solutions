class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>v1(n,0),v2(n,1);
        for(int i=1;i<n;i++)
        {
            v1[i]=v2[i]=n;
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i])
            {
                v1[i]=v1[i-1];
                v2[i]=v2[i-1]+1;
            }
            if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i])
            {
                v1[i]=min(v2[i-1],v1[i]);
                v2[i]=min(v1[i-1]+1,v2[i]);
            }
        }
        return min(v1[n-1],v2[n-1]);
        
    }
};