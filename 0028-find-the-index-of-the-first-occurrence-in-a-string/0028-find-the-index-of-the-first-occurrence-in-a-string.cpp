class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        if(n>haystack.size())return -1;
       // if(needle==haystack)return 0;
        for(int i=0;i<haystack.size()-n+1;i++)
        {
            string s1=haystack.substr(i,n);
            if(s1==needle)return i;
        }
        return -1;
    }
};