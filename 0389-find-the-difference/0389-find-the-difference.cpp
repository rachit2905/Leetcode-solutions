class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0;
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;j++;
            }
            else return t[j];
        }
        return t[j];
    }
};