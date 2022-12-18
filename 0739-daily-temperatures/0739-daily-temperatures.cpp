class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
    int n = tmp.size();
            vector<int> ans(n, 0);
            stack<int> st;
            st.push(0);
            int i = 1;
            while (i < n)
            {
                if (st.empty()) // if stack is empty
                {
                    st.push(i);
                    continue;
                }

                while (!st.empty() && tmp[i] > tmp[st.top()])  // if we see greater element
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
                i++;
            }

            return ans;
    }
};