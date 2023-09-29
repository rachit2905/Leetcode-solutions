class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>temp1=nums;
        vector<int>temp2=nums;
        sort(temp1.begin(),temp1.end());
        sort(temp2.rbegin(),temp2.rend());
        if(nums==temp1 || nums==temp2)return 1;
        return 0;
    }
};