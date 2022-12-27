class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& ro, int ar) {
        vector<int>v1;
        for(int i=0;i<cap.size();i++)
        {
            v1.push_back(cap[i]-ro[i]);
            
        }
        sort(v1.begin(),v1.end());
        int ans=count(v1.begin(),v1.end(),0);
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=0 && v1[i]<=ar)
            {
                ans++;
                ar-=v1[i];
            }
            else if(ar<=0)return ans;
        }
       return ans; 
    }
};