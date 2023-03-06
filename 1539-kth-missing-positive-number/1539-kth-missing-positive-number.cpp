class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int k1 = 0, m = 1, i = 0;
            while (i < arr.size())
            {
                if (arr[i] != m)
                {
                    m++;
                    k1++;
                }
                else
                {
                    m++;
                i++;}
                if (k1 == k) return m-1;
            }
            while (k1 != k)
            {
                k1++;
                m++;
            }
            return m-1;
        }
};