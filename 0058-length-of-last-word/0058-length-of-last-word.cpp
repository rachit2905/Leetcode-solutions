class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        if(i==0 || (i==1&& s[i]==' '))return 1;
        while(i>=0 && s[i]==' ')
            i--;
        int co=0;
        while(i>0 && s[i]!=' ')
        {
            i--;co++;
        }
        if(s[i]!=' ')
        return co+1;
        else return co;
    }
};