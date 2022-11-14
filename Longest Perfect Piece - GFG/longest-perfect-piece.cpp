//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
            multiset<int>st;
       int mx=0;
     int i=0,j=0;
     while(i<N )
       {
           st.insert(arr[i]);
           if(st.size()>1)
           {
               auto s=st.begin();
               auto e=st.rbegin();
           while(*e-*s>1)
               {
                   st.erase(st.find(arr[j]));
                   j++;
                      s=st.begin();
                e=st.rbegin();
                   
               }
               
           }
           if((int)st.size()>mx)
           {
           mx=(int)st.size();
           }
           i++;
       }
       return mx;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends