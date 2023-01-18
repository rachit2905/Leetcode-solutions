class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<int>prices(n,INT_MAX);
        vector<int>temp=prices;
        prices[src]=0;temp[src]=0;
        for(int i=0;i<k+1;i++)
        {
            // temp=prices;
            for(int i=0;i<flights.size();i++)
            {
                if(prices[flights[i][0]]!=INT_MAX)
                {
                   // cout<<flights[i][1]<<"\n";
                    if(temp[flights[i][1]]>prices[flights[i][0]]+flights[i][2])
                        temp[flights[i][1]]=prices[flights[i][0]]+flights[i][2];
                }
            }
            prices=temp;
        }
        if(prices[dst]==INT_MAX)return -1;
        else return prices[dst];
    }
};