class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& ro, int ar) {
        //vector<int>v1;
        for(int i=0;i<cap.size();i++)
        {
            cap[i]=(cap[i]-ro[i]);
            
        }
        sort(cap.begin(),cap.end());
        int ans=count(cap.begin(),cap.end(),0);
        for(int i=0;i<cap.size();i++)
        {
            if(cap[i]!=0 && cap[i]<=ar)
            {
                ans++;
                ar-=cap[i];
            }
            else if(ar<=0)return ans;
        }
       return ans; 
    }
};