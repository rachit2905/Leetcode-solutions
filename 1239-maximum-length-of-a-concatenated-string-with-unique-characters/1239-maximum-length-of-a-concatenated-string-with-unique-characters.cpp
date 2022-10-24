class Solution {
    int countSetBits(int &num)
    {
        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if( ((1 << i) & num) > 0)
                count++;
        }
        return count;
    }
    
    pair<bool, int> isPossible(int &set, string &str)
    {
        int bitRep = 0;
        for(char ch : str)
        {
            int idx = ch - 'a';
            int temp = 1 << idx;
            if( (temp & bitRep) > 0 || (temp & set) > 0)
                return {false, set};
            bitRep |= temp;
        }
        set |= bitRep;
        return {true, set};
    }
    
    void solve(int idx, int n, int set, int &res, vector<string>& arr)
    {
        if(idx == n)
        {
            int setBits = countSetBits(set);
            res = max(res, setBits);
            return;
        }
        
        solve(idx + 1, n, set, res, arr);
        
        pair<bool, int> possible = isPossible(set, arr[idx]);
        if(possible.first)
            solve(idx + 1, n, possible.second, res, arr);
    }
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        solve(0, arr.size(), 0, res, arr);
        return res;
    }
};