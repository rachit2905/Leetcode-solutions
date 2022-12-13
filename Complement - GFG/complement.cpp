//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        vector<pair<int,int>>v1;
        int ze=0,on=0,ansl=0,ansr=0,mx=INT_MIN,l=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')ze++;
            else on++;
            if(ze<on)
            {
                l=i+1;
                ze=0,on=0;
            }
            else if(mx<ze-on)
            {
                mx=max(mx,ze-on);
                ansl=l;
                ansr=i+1;
            }
        }
        if(mx==INT_MIN)
        return {-1};
        else return {ansl+1,ansr};
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends