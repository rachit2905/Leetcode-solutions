class Solution {
public:
    
    bool check(int n1,int sum, int sqre,int n)
    {
        if(n1+sum==n)
        {
            return true;
        }
        int tens=10;
        while(n1/tens!=0)
        {
            int nsum= sum + (n1%tens);
            
            int nn1= (n1/tens);
            bool ans=check(nn1,nsum, sqre,n);
            
            if(ans==true)
            {
                return true;
            }
                
            tens=tens*10;
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        vector<int>dp(n+1,0);
        for(int i=1; i<=n;i++)
        {
            int curr=0;
            if(check(i*i,0,i*i,i))
            {
                curr=i*i;
            }    
            dp[i]=dp[i-1]+curr;
        }
        for(int i=0; i<n+1;i++)
        {
            cout<<dp[i]<<" ";
        }
        return dp[n];
    
    }
};