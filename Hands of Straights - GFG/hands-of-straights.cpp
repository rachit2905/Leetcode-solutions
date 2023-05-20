//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        map<int,int>m1;
        if(N%groupSize!=0)return 0;
        for(auto it:hand)
        {
            m1[it]++;
        }
        
        for(int i=0;i<N/groupSize;i++)
        {
           auto it=m1.begin();
           int x=it->first;
           m1[x]--;
           if(m1[x]==0)m1.erase(m1.find(x));
           for(int j=0;j<groupSize-1;j++)
           {
               it++;
               if(it!=m1.end() && it->first-x==1)
               {
                   x=it->first;
                   m1[x]--;
                   if(m1[x]==0)m1.erase(m1.find(x));
               }
               else return 0;
           }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends