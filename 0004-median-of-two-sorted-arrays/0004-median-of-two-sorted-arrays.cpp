class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v1;
        for(auto it:nums1)
        {
            v1.push_back(it);
        }
        for(auto it:nums2)
            v1.push_back(it);
        sort(v1.begin(),v1.end());
        if(v1.size()%2)
        {
            return v1[v1.size()/2];
        }
        else
        {
            return (v1[v1.size()/2]+v1[(v1.size()/2)-1])/2.0;
        }
    }
};