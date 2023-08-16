class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>pq;
        for(int i=0;i<k;i++)
            pq.insert(nums[i]);
        int co=k,co1=0;
        ans.push_back(*(--pq.end()));
        while(co<nums.size())
        {
            pq.insert(nums[co]);
            pq.erase(pq.find(nums[co1++]));
            ans.push_back(*(--pq.end()));co++;
        }
        
        return ans;
            
    }
};