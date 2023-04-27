//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        
        vector<char> res;
        
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == "1")
                s[stoi(queries[i][1])] = (char)queries[i][2][0];
            
            else{
                
                int left = stoi(queries[i][1]), right = stoi(queries[i][2]);
                int index = stoi(queries[i][3]);
                
                int arr[26] = {0};
                
                for(int j = left; j <= right; j++)
                    arr[s[j] - 'a']++;
                
                
                int count = 0;
                
                for(int j = 25; j >= 0; j--){
                    count += arr[j];
                    if(count >= index){
                        res.push_back(j + 'a');
                        break;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends