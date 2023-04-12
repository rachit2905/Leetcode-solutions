class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
         vector<vector<int>>v(n,vector<int>(n,1));
        for (int i=0;i<mines.size();i++)
        {
          v[mines[i][0]][mines[i][1]]=0;
        }
        vector<vector<int>>L(n,vector<int>(n));
         vector<vector<int>>R(n,vector<int>(n));
          vector<vector<int>>U(n,vector<int>(n));
           vector<vector<int>>D(n,vector<int>(n));
           for (int i=0;i<n;i++)
           {
               int cnt=0;
               for (int j=0;j<n;j++)
               {
                   if (v[i][j]==1)
                   {
                       cnt++;
                       L[i][j]=cnt;
                   }
                   else {
                       cnt=0;
                       L[i][j]=cnt;
                   }
               }
           }
           for (int i=0;i<n;i++)
           {
               int cnt=0;
               for (int j=n-1;j>=0;j--)
               {
                   if (v[i][j]==1)
                   {
                       cnt++;
                       R[i][j]=cnt;
                   }
                   else {
                       cnt=0;
                       R[i][j]=cnt;
                   }
               }
           }
           for (int j=0;j<n;j++)
           {
               int cnt=0;
               for (int i=0;i<n;i++)
               {
                   if (v[i][j]==1)
                   {
                       cnt++;
                       U[i][j]=cnt;
                   }
                   else {
                       cnt=0;
                       U[i][j]=cnt;
                   }
               }
           }
           for (int j=0;j<n;j++)
           {
               int cnt=0;
               for (int i=n-1;i>=0;i--)
               {
                   if (v[i][j]==1)
                   {
                       cnt++;
                       D[i][j]=cnt;
                   }
                   else {
                       cnt=0;
                       D[i][j]=cnt;
                   }
               }
           }
           int ans=0;
           int res=0;
           for (int i=0;i<n;i++)
           {
               for (int j=0;j<n;j++)
               {
                ans=min(L[i][j],R[i][j]);
                ans=min(ans,U[i][j]);
                ans=min(ans,D[i][j]);
                 res=max(res,ans);
               }
           }
           return res;
          
    }
};