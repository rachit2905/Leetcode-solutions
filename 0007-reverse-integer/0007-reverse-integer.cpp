class Solution {
public:
    int reverse(int x) {
        string s1=to_string(x);
        string s2="";
        for(auto it:s1)
        {
            s2=it+s2;
        }
        s1=s2;
        if(s1[s1.length()-1]=='-')
        {
            s1="-"+s1;
            s1=s1.substr(0,s1.length()-1);
        }
        long long int n1=stoll(s1);
        if(n1>=-(pow(2,31)) && n1<=(pow(2,31)-1))return n1;
        else return 0;
    }
};