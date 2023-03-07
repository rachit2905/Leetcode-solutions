class Solution
{
    public:
        bool func(long long mid, long long int totalTrips, vector< int> &time) 
        {
            long long x=0;
            for(auto it:time)
            {
                x+=(mid/it);
            }
            return x>=totalTrips;
        }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        sort(time.begin(), time.end());
        long long hi = ( long long)time[time.size() - 1] *( long long)totalTrips;
        long long lo = 1;
        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (func(mid, totalTrips, time))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};