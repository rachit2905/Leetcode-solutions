//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<vector<string>> displayContacts(int n, string contacts[], string s)
    {
        // code here
        vector<vector<string>> ans;
        map<string,set<string>> mp;
        
        for(int i = 0;i < n; i++){
            string contact = contacts[i];
            string str = "";
            for(int i=0;i<contact.size();i++){
                str+=contact[i];
                mp[str].insert(contact);
            }
        }
        
        string prefix = "";
        
        for(int i=0;i<s.size();i++){
            prefix += s[i];
            if(mp.find(prefix) != mp.end()){
                //sort(mp[prefix].begin(),mp[prefix].end());
                set<string> s = mp[prefix];
                vector<string> v(s.begin(),s.end());
                ans.push_back(v);
            }
            else{
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends