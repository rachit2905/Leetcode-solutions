class Solution {
public:
    bool find132pattern(vector<int>& nums) {
          
        int n=nums.size();

        if(n<3){
            return false;
        }




        stack<int>st;

        int c=INT_MIN;

        for(int i=nums.size()-1;i>=0;i--){

            int curr=nums[i];

            if(c>curr){
                return true;
            }

            while(!st.empty() and st.top()<curr){
                c=st.top();
                st.pop();
            }

            st.push(curr);


        }

        return false;
    }
};