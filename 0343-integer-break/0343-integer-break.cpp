class Solution {
public:
     int integerBreak(int n) {
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0) ;
        
        for(int j = 0; j <= n; j++)
            prev[j] = 1;
        
        for(int ind = 2; ind < n; ind++)
        {
            for(int target = 0; target <= n; target++)
            {
                int notPick = prev[target];
        
                int pick = 0;
                if(target >= ind)
                    pick = ind * curr[target - ind];

                curr[target] = max(pick, notPick);
            }
            
            prev = curr;
        }
        
        return prev[n];
       
    }
};