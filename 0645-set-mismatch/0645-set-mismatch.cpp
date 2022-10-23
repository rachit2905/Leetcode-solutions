class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>m1;
        int x,y;
        for(auto it:nums)m1[it]++;
        for(auto it:m1)if(it.second>1){x=it.first;break;}
        for(int i=1;i<=nums.size();i++)
        {
            if(m1.find(i)==m1.end())
            {
                y=i;break;
            }
        }
        return {x,y};
    }
};