class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector < int>> ans;
          sort(nums.begin(),nums.end());
            ans.push_back( {});
            for (int i = 0; i < nums.size(); i++)
            {

                int x = nums[i];
                int sz = ans.size();
                for (int i1 = 0; i1 < sz; i1++)
                {
                    vector<int> ans1;
                    ans1.push_back(x);

                    for (auto it: ans[i1])
                        ans1.push_back(it);

                    ans.push_back(ans1);
                }
            }
        set<vector<int>>anss;
        for(auto it:ans)
        {
            anss.insert(it);
        }
        vector<vector<int>>ans1;
        for(auto it:anss)
            ans1.push_back(it);
            return ans1;
    }
};