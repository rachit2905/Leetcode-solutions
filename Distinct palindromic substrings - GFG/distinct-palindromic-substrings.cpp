//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{

  public:

  bool isPalindrome(string S)

{

    int i=0,j;

    j = S.size() - 1;

    while (i < j)

    {

        if (S[i] != S[j])

        {

            return false;

        }

        i++; j--;

    }

    return true;

}

    int palindromeSubStrs(string s) {

       int n=s.size();

       string str="";

       set<string>st;

       int cnt=0;

       for(int i=0;i<n;i++){

           str="";

           for(int j=i;j<n;j++){

               str+=s[j];

           if( isPalindrome(str)) {

               st.insert(str);

           }  

           }

       }

       return st.size();

    }

};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends