//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
static bool cmp(string s1,string s2)
{
    if(s1.length()==s2.length())return s1>s2;
    else return s1.length()<s2.length();
}
    string longestString(vector<string> &words)
    {
        // code here
        vector<string>ans;
        sort(words.begin(),words.end(),cmp);
        for(int i=words.size()-1;i>=0;i--)
        {
            bool co=true;//cout<<words[i]<<"\n";
            for(int j=0;j<words[i].length();j++)
            {
                
                string s1=words[i].substr(0,j+1);
                if(find(words.begin(),words.end(),s1)==words.end())
                {
                    co=false;break;
                }
            }
            if(co)return words[i];
            else continue;
        }
        if(ans.size()==0)return "";
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends