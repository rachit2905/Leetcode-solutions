class Solution {
public:
    bool detectCapitalUse(string word) {
       string s1=word;
        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
        if(s1==word)
        {
            return 1;
        }
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        if(s1==word)
            return 1;
    //    bool co=true;
        if(islower(word[0]))return 0;
        for(int i=1;i<word.length();i++)
        {
            if(isupper(word[i]))return 0;
        }
        return 1;
    }
};