class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
            vector<long long> pf; long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pf.push_back(sum);
        }
        
        long long mind = 1e5, minind = 0;
        for(int i=0;i<n;i++){
            if(n-i-1>0){
                if(abs((pf[i]/(i+1))-((pf[n-1] - pf[i])/(n-i-1))) < mind){
                    mind = abs((pf[i]/(i+1))-((pf[n-1] - pf[i])/(n-i-1)));
                    minind = i;
                }
            }else {
                if(abs((pf[i]/(i+1)) - 0) < mind){
                    mind = abs((pf[i]/(i+1)) - 0);
                    minind = i;
                }
            }
        }
        return minind;
    }
};