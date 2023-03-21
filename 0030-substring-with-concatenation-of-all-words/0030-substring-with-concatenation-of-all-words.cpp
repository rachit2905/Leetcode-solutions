class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
     map<string,int>m1,m2;vector<int>ans;
        for(auto it:words)m1[it]++;
        m2=m1;
        for(int i=0;i<s.length()-words[0].length()+1;i++)
        {
            string s1=s.substr(i,words[0].length());
            if(m2[s1])
            {
               //cout<<i<<"\t"; 
                int co=1;
                m2[s1]--;
                int j=i+words[0].length();
                while(j<(s.length()-words[0].length()+1) && co<words.size())
                {
                     //cout<<j<<" ";
                    string s2=s.substr(j,words[0].length());//cout<<m2[s2]<<" "<<s2<<"\n";
                    if(m2[s2]){
                        co++;
                        m2[s2]--;
                        j+=words[0].length();
                    }
                    else
                        break;
                   
                }//cout<<"\n";
                if(co==words.size()){ans.push_back(i);m2=m1;}
                else m2=m1;
            }
        }
        return ans;
    }
};