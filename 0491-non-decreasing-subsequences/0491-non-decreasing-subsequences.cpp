class Solution {
public:
     vector<vector<int>> ans;
    void solve(vector<int>& nums, int index, vector<int>& temp) {
        if(index == nums.size()) {
            if(temp.size() > 1 )
                ans.push_back(temp);
            return ;
        }
        if(temp.empty() || temp.back() != nums[index]){
            solve(nums, index+1, temp);
        }
        if(temp.empty() || nums[index] >= temp.back()){
            temp.push_back(nums[index]);
            solve(nums,index+1, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        return ans;
    }
};