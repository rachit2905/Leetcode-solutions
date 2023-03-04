class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        //sort(nums.begin(),nums.end());
        set<int>s1;int co=1,ans=0;
        for(auto it:nums)s1.insert(it);
        int i=*s1.begin();
        for(auto it=++s1.begin();it!=s1.end();it++)
        {
            if(*it-i==1)
                co++;
            else
            {
                ans=max(ans,co);
                co=1;
            }
            i=*it;
        }
        return max(ans,co);
        
    }
};