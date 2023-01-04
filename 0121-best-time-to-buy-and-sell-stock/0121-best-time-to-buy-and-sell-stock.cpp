class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN,x=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(x>prices[i])
                x=prices[i];
            else
                ans=max(ans,prices[i]-x);
        }
        return max(ans,0);
    }
};