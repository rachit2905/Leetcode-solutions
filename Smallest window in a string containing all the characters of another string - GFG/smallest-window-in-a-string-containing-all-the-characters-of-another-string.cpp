//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
         int n = s.size();
        int m = p.size();
        
        if(n<m)
            return "-1";
        
        int count  = 0;
        
        int len = INT_MAX; //length of ans string
        int start = 0; // start of ans string
        
        unordered_map<char,int>mp;
        
        for(char c:p){
            if(mp[c]== 0)
            count++;
            
            mp[c]++;
        }
        
        int i = 0;//start of window
        int j = 0;//end of window
        
        while(j<s.size()){
            mp[s[j]]--;
            
            if(mp[s[j]]==0)
            count--;
            
            
            if(count==0){
                while(count==0){
                    if(len>j-i+1){
                        len = min(len,j-i+1); //updating length
                        start = i; //updating new start
                    }
                    
                    mp[s[i]]++;
                    
                    if(mp[s[i]]>0)
                    
                    count++;
                    
                    i++;
                }
            }
            j++;
        }
        
        if(len!=INT_MAX)
        return s.substr(start,len);
        
        else
        return "-1";
    
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends