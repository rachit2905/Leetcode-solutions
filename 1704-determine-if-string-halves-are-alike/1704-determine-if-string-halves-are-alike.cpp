class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            string s1 = s;
            s = s.substr(0, s.length() / 2);
            s1 = s1.substr(s1.length() / 2);
            
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            int x = count(s1.begin(), s1.end(), 'a') + count(s1.begin(), s1.end(), 'e') +
                count(s1.begin(), s1.end(), 'i') +
                count(s1.begin(), s1.end(), 'o') +
                count(s1.begin(), s1.end(), 'u');
            int y = count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'e') +
                count(s.begin(), s.end(), 'i') +
                count(s.begin(), s.end(), 'o') +
                count(s.begin(), s.end(), 'u');
            if(x==y)return 1;
            else return 0;
        }
};