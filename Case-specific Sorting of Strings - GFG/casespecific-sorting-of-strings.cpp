//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string s1="",s2="";
    string caseSort(string str, int n)
    {
        // your code here
        for(auto it:str)
        {
            if(it>='a' && it<='z')
            s1+=it;
            else
            s2+=it;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int i=0,k=0;
        for(int j=0;j<str.length();j++)
        {
            if(str[j]>='a' && str[j]<='z')
            {
                str[j]=s1[i];
                i++;
            }
            else
            {
            str[j]=s2[k];
            k++;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends