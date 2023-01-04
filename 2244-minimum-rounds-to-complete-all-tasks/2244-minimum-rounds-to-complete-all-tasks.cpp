class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m1;
        for(auto it:tasks)
        {
            m1[it]++;
        }
        int ans=0;
        for(auto it:m1)
        {
            if(it.second>=3)
            {
                if(it.second%3==0)
                {
                    ans+=it.second/3;
                }
                else
                    ans+=(it.second/3)+1;
            }
            else if(it.second==2)
                ans+=1;
            else return -1;
        }
        return ans;
    }
};