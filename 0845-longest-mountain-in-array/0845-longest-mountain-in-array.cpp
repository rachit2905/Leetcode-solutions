class Solution {
public:
    int longestMountain(vector<int>& nums) 
    {
        int n = nums.size();
        int largest = 0;

        // first and last element won't be peak for sure

        for(int i = 1; i< n-1 ; )
        {
            int count = 1;

            // checking if nums[i] is a peak

            if(nums[i] > nums[i-1] and nums[i] > nums[i+1])
            {

                // traversing the left part till the bottom of the mountain
                int j = i;

                while( j >= 1 and nums[j] >nums[j-1])
                {
                    count++;
                    j--;
                }

                // traversing the right part till the bottom of the mountain

                while(i < n-1 and nums[i] > nums[i+1])
                {
                    i++;
                    count++;
                }

                largest = max(largest, count);

            }
            // if nums[i] isn't a peak, we simply need to check further
            else
            {
                i++;
            }
        }

        return largest;
        
    }
};