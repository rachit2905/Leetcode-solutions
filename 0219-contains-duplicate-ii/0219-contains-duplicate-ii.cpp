class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	//we will create an unordered map for handling multiple occurence of a number
	//this will also help us in maintaing the insert , search, update and delete operations in O(1) time complexity
        unordered_map<int,int>st;
		//we will have two pointer 1 at the begin of the window and second at the end of the window
        int i = 0,j = 0;
		
        for(; j<nums.size(); j++){
		//when the size of the window increases than the given size then remove element at the front of the window
		//here we are using maps so we will do map[key]--, where key = nums[i] element to which 1st pointer is pointing, then we increment the beginning of the window
            if(j>k){
                st[nums[i++]]--;
            }
            //we check is the current element has seen before in the window
			//if the occurence of the element is greater than 0 then it means it was present in the window size
            if(st[nums[j]]>0){
                return true;
            }
            //if the above cases are not applicable then we simply insert the current element into the map container
            st[nums[j]]++;
        }
		
        return false;
    }
};