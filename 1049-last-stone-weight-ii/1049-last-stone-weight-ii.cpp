class Solution {
public:
    int lastStoneWeightII(vector<int>& st) {
         int n=st.size();
        int sum=0;
        //find sum of all
        for(int i=0;i<n;i++)
            sum+=st[i]; 
        //applied algo to find if given sum is present or not in the array
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<sum+1;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(st[i-1]<=j)
                    dp[i][j]=dp[i-1][j-st[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        //simply see the target one by one so that the absolute difference between the sum of subsets become minimum
        for(int x=sum%2==0?sum/2:sum/2+1;x<=sum;x++){
        if(dp[n][x]==true)//if find any then return that otherwise increment and check again
            return 2*x-sum;
            }
        return 0;
    }
    
};