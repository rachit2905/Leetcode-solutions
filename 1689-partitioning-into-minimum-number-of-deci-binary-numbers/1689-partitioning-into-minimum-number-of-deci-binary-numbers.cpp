class Solution {
public:
    int minPartitions(string n) {
        // sort(n.begin(),n.end());
        // return n[n.size()-1]-'0';
        int ans=0;
        for(auto it:n)
        {
            ans=max(ans,it-'0');
        }
        return ans;
    }
};