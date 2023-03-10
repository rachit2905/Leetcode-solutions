class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m1,m2;
        for(auto it:letters)
            m1[it]++;
        m2=m1;
        int n=words.size(),ans=0;
        for(int i=0;i<pow(2,n);i++)
        {
            string s="";
            int x=i;
            while(x>0)
            {
                if(x%2)s="1"+s;
                else s="0"+s;
                x/=2;
            }
            
            while(s.length()<n)
            {
                s="0"+s;
            }
            int co1=0,ans1=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    int co=0;
                  // string s1=words[i];
                    int ans2=0;
                   for(auto it:words[i])
                   {
                       if(m1[it]>0)
                       {
                           m1[it]--;
                           ans2+=score[it-'a'];
                       }
                       else
                           co=1;
                   }
                    if(!co)ans1+=ans2;
                    else {co1=1;break;}
                }
            }
            m1=m2;
            if(co1)continue;
            else
               ans=max(ans,ans1);
        }
        return ans;
    }
};