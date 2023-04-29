class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       map<int,int>m1;
        for(auto it:nums)
        {
            m1[it]++;
        }
        int k=0;
        for(auto it:m1)
        {
            int co=min(it.second,2);
            while(co)
            {
                nums[k]=it.first;
                k++;
                co--;
            }
            
        }
        return k;
    }
};