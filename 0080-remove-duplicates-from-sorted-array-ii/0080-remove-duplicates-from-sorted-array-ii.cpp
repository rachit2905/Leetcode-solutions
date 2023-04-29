class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
        {
            return n;
        }
        int l=2,h=2;
        while(l<n && h<n)
        {
            if(nums[h] == nums[l-2])
            {
                h++;
            }
            else
            {
                nums[l] = nums[h];
                l++;
                h++;
            }
        }
        return l;
    }
};