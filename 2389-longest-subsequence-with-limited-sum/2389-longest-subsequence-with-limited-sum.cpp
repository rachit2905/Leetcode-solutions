class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto it:queries)
        {
            int co=0,i=0;
            while(i<nums.size() && co<it)
            {
                co+=nums[i];i++;//cout<<co<<"\n";
            }
            if(co<=it)
            ans.push_back(i);
            else
                ans.push_back(i-1);
        }
        return ans;
    }
};