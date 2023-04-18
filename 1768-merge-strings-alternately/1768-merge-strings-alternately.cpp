class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=min(word1.length(),word2.length());
        string ans="";
        for(int j=0;j<i;j++)
        {
            ans+=word1[j];ans+=word2[j];
        }
        while(i<=word1.length()-1)
            ans+=word1[i++];
        while(i<=word2.length()-1)ans+=word2[i++];
        return ans;
    }
};