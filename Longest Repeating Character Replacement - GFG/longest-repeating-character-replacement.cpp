//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
         int n = s.length();
        int left = 0; //->window start
        int right = 0; //->window end
        int currStrLen = 0;
        int LongestStrLen = -1;
        int maxRepeatingChar = 0; //->max no of repeating elements 
        unordered_map<char, int> umap;
        while (right < n)
        {
            umap[s[right]]++;
            maxRepeatingChar = max(maxRepeatingChar, umap[s[right]]);
            currStrLen = (right - left) + 1; //Curr Len of the window
            if ((currStrLen - maxRepeatingChar) > k) // the curr window has more than k replacable items case
            {
                umap[s[left]]--;
                left++; // shrinking the window
            }
            currStrLen = (right - left) + 1; // just in case i is changed
            LongestStrLen = max(LongestStrLen, currStrLen);
            right++;
        }
        return LongestStrLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends