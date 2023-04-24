class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        int n = nums.size();
        unordered_map<int,int>m; 
        priority_queue<int>maxh; 
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(int i=0;i<k;i++) {
            maxh.push(nums[i]);
        }
         for(int i=0;i<(k/2);i++) {
            minh.push(maxh.top());
            maxh.pop();
        }
        for(int i=k;i<n;i++) {
            if(k&1) {
                ans.push_back(maxh.top()*1.0);
            }
            else {
                ans.push_back(((double)maxh.top()+(double)minh.top())/2);
            }
            int p=nums[i-k], q=nums[i]; 
            int balance = 0; 
            if(p<=maxh.top()) { 
                balance--;
                if(p==maxh.top())
                    maxh.pop();
                else
                    m[p]++;
            }
            else { 
                balance++;
                if(p == minh.top())
                    minh.pop();
                else
                    m[p]++;
            }
            
            if(!maxh.empty() and q<=maxh.top()) { 
                maxh.push(q);
                balance++;
            }
            else { 
                minh.push(q);
                balance--;
            }
            
            if(balance<0) {
                maxh.push(minh.top());
                minh.pop();
            }
            else if(balance>0) {
                minh.push(maxh.top());
                maxh.pop();
            }
            
            while(!maxh.empty() and m[maxh.top()]) {
                m[maxh.top()]--;
                maxh.pop();
            }
            while(!minh.empty() and m[minh.top()]) {
                m[minh.top()]--;
                minh.pop();
            }
        }
        if(k&1) {
            ans.push_back(maxh.top()*1.0);
        }
        else {
            ans.push_back(((double)maxh.top()+(double)minh.top())/2.0);
        }
        return ans;
    }
};
