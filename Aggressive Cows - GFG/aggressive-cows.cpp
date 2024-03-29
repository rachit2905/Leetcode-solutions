//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

     bool isPossible(vector<int>v,int n,int cow,int mid)

 {

     int cowCount = 1;

     int lastPos = v[0];

     

     for(int i=0;i<n;i++)

     {

         if(v[i]-lastPos >=mid)

         {

             cowCount++;

             

             if(cowCount==cow)

              return true;

             

             lastPos = v[i];

         }

     }

     

     return false;

 }

 

    int solve(int n, int k, vector<int> &v) {

       

       sort(v.begin(),v.end());

       

        int ans=-1;

    

        int maxi = INT_MIN;

        

        for(int i=0;i<n;i++)  //This is to find the largest distance betweeen two cow

        {

            if(v[i]>maxi)

             maxi=v[i];

        }

        

        int start = 0;

        int end = maxi;

        

        while(start<=end)

        {

            int mid = start+(end-start)/2;

            

            if(isPossible(v,n,k,mid))

            {

                ans = mid;

                

                start = mid+1;

            }

            

            else

             end = mid-1;

        }

        

        return ans;

    }
    
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends