class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
     if(dict.size()==0) return false;

        int longestWord = 0;
        for(string word : dict){
            longestWord = max(longestWord, (int)word.size());
        }

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=max(i-longestWord, 0);j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(find(dict.begin(),dict.end(),word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];

    }
};