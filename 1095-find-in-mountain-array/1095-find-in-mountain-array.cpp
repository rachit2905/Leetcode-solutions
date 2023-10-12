class Solution {
public:
    int findInMountainArray(int target, MountainArray &mArray) {
        int n = mArray.length();
        
        // Binary search to find the peak element
        int left = 0, right = n - 1;
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            int midValue = mArray.get(mid);
            int nextValue = mArray.get(mid + 1);
            
            if (midValue < nextValue) left = mid + 1;
            else  right = mid;
        }
        
        int peak = left;  // Peak index
        
        // Search in the left side of the peak
        left = 0;
        right = peak;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mArray.get(mid);
            
            if (midValue == target) return mid;
            else if (midValue < target) left = mid + 1;
            else right = mid - 1;
            
        }
        
        // Search in the right side of the peak
        left = peak;
        right = n - 1;
        
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            int midValue = mArray.get(mid);
            
            if (midValue == target) return mid;
            else if (midValue < target) right = mid - 1;
            else left = mid + 1;
            
        }
        
        return -1;  // Target not found in the MountainArray
    }
};