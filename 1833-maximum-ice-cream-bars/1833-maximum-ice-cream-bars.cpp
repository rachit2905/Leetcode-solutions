class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        if(costs[0]>coins)return 0;
        int ans=0,sum=0;
        for(auto it:costs)
        {
            if(sum+it<=coins)
            {
            sum+=it;
            ans++;}
            if(sum>=coins)return ans;
            
        }
        return ans;
    }
};