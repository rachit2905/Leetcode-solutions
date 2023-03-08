class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            if(heights.size()==1)return heights[0];
            stack<int> s1;
            vector<int> nsl, nsr;
            int n = heights.size();
            for (int i = 0; i < n; i++)
            {
                while (!s1.empty() && heights[s1.top()] >= heights[i])
                {
                    s1.pop();
                }
                if (s1.empty()) nsl.push_back(-1);
                else nsl.push_back(s1.top());
                s1.push(i);
            }
            while (!s1.empty()) s1.pop();
            for (int i = n - 1; i >= 0; i--)
            {
                while (!s1.empty() && heights[s1.top()] >= heights[i])
                {
                    s1.pop();
                }
                if (s1.empty()) nsr.push_back(-1);
                else nsr.push_back(s1.top());
                s1.push(i);
            }
            reverse(nsr.begin(), nsr.end());
            int ans = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                int temp = 0;
                if (nsl[i] == -1 || nsr[i] == -1)
                {
                    if (nsl[i] == -1)
                    {
                        temp += heights[i] *(i);
                    }
                    if (nsr[i] == -1)
                    {
                        temp += heights[i] *(n - 1 - i);
                    }
                }
                if (nsl[i] != -1)
                {
                    temp+=heights[i]*(i-nsl[i]);
                }
                if(nsr[i]!=-1)
                {
                    temp+=heights[i]*(nsr[i]-i);
                }
                if(nsl[i]!=-1 && nsr[i]!=-1)temp-=heights[i];
                if(nsl[i]==-1 && nsr[i]==-1)temp+=heights[i];
                cout<<temp<<" ";
               ans=max(ans,temp);
            }
            return ans;
        }
};