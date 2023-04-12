class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int sz = 0, i = 0, j = 0, su = 0, n = nums.size();

            while (j < n && su < target)
            {
                su += nums[j++];
            }
            if (su < target) return 0;
           // if(j==n)j--;
            sz = j - i;
            while (j <= n-1)
            {
                su += nums[j];
                while (su > target)
                {
                    if (su - nums[i] >= target)
                    {
                        su -= nums[i];
                        i++;

                        
                    }
                    else
                        break;
                }sz = min(sz, j - i + 1);
                cout << i << " " << j << "\n";
                j++;
            }
            if (su >= target)
            {
                if(j==n)j--;
                while (su > target)
                {
                    if (su - nums[i] >= target)
                    {
                        su -= nums[i];
                        i++;
                    }
                    else break;
                }
                sz = min(sz, j - i + 1);
            }
            return sz;
        }
};