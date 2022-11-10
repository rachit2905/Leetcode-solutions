//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:


void f(int last,long long t,long long x,long long &ans)

  {

      if(t>x) return;

      if(t<=x)

      {

          ans=max(ans,t);

      }

// two calls will be made one for the next digit should be 1 less than the last digit and one for the next digit should be 1 more than the last digit.

      if(last+1<=9) f(last+1,t*10+(last+1),x,ans);

      if(last-1>=0) f(last-1,t*10+(last-1),x,ans);

  }

    long long jumpingNums(long long x) {

        // code here

        if(x<=10) return x; //self explanatory.

        long long ans=-1;

        for(int i=1;i<=9;i++)

        {

            f(i,i,x,ans);

        }

        return ans;

        

 

    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends