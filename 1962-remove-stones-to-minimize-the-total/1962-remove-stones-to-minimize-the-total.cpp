class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int>s1;
        for(auto it:piles)
        {
            s1.push(it);
        }
        while(k--)
        {
           int temp=s1.top();
            s1.pop();
            s1.push(ceil(temp/2.0));
        }
        int ans=0;
        while(!s1.empty())
        {
            ans+=s1.top();
            s1.pop();
        }
        return ans;
    }
};