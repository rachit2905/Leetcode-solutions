class Solution
{
    public:
        bool static cmp(vector<int> &a, vector<int> &b) {return a[1] < b[1];}

    int findMinArrowShots(vector<vector < int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int in = points[0][1], n = points.size(), ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (in >= points[i][0] && in <= points[i][1])
            {
                continue;
            }
            else
            {
                ans++; in = points[i][1];
            }
            cout << in << " ";
        }
       	//if(in!=points[n-1][1])ans++;
        return ans;
    }
};