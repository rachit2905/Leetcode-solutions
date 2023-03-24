//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
         unordered_map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        string ans1="";
        string ans2="";
        int i=0,e=n-1;
        int f=1;
        int cnt=0;
            while(i<=e){
                if(f==1){
                    if(m[s[i]]>1){
                        m[s[i]]--;
                        f=0;
                        i++;
                        cnt++;
                    }else if(m[s[i]]==1){
                        ans1+=s[i];
                        i++;
                    }
                }else{
                    if(m[s[e]]>1){
                        m[s[e]]--;
                        f=1;
                        e--;
                        cnt++;
                    }else if(m[s[e]]==1){
                        ans2+=s[e];
                        e--;
                    }
                }
            }
            reverse(ans2.begin(),ans2.end());
            string ans=ans1+ans2;
            if(cnt%2!=0){
                reverse(ans.begin(),ans.end());
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends