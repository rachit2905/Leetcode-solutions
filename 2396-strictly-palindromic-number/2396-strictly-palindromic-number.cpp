class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int n1=n;
        for(int i=2;i<=n-2;i++)
        {
            n1=n;
            string s1="";
            while(n1)
            {
                s1+=to_string(n1%i);
                n1/=i;
                
            }
            string s2=s1;
            reverse(s2.begin(),s2.end());
            if(s2!=s1)return 0;
            cout<<s1<<" ";
        }
        return 1;
    }
};