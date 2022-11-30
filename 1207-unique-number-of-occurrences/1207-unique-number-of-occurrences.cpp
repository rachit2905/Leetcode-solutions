class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m1;
        for(auto it:arr)
        {
            m1[it]++;
        }
        set<int>s1;
        for(auto it:m1)
        {
            s1.insert(it.second);
        }
        if(s1.size()==m1.size())return 1;
        else return 0;
    }
};