class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pr=0,curr=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            pr=max(pr,prices[i]-curr);
            curr=min(curr,prices[i]);
        }
        return pr;
    }
};