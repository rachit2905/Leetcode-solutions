class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int>prices(n,INT_MAX),temp(n,INT_MAX);
        prices[src]=temp[src]=0;
        for(int i=0;i<k+1;i++)
        {
            for(int j=0;j<flights.size();j++)
            {
                if(prices[flights[j][0]]!=INT_MAX)
                {
                if(temp[flights[j][1]]>prices[flights[j][0]]+flights[j][2])
                    temp[flights[j][1]]=prices[flights[j][0]]+flights[j][2];
            }
            }
            prices=temp;
        }
        if(prices[dst]==INT_MAX)
            return -1;
        else return prices[dst];
    }
};