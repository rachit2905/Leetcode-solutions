//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    //string s1=num;
    int n=num.length();
    stack<char>s1;
    s1.push(num[0]);
    for(int i=1;i<n;i++)
    {
        while(!s1.empty() && s1.top()>num[i] && k!=0)
        {
            s1.pop();k--;
        }
        s1.push(num[i]);
    }
    string res="";
    while(!s1.empty())
    {
    char c=s1.top();
    s1.pop();
    if(k>0)
    {
        k--;
        continue;
        
    }
    res+=c;
    }
    //cout<<res<<"\n";
    reverse(res.begin(),res.end());
    for(int i=0;i<res.length();i++)
    {
        if(res[i]!='0')
        {
        res=res.substr(i);
        return res;
        }
    }
    return "0";
}