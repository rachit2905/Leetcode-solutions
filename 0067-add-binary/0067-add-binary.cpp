class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.length() - 1;
        int j = b.length() - 1;
        string ans;
        int rem = 0;
        while(i >= 0 || j >= 0){
            int temp = 0;
            if(i >= 0) temp += a[i] - '0';
            if(j >= 0) temp += b[j] - '0'; 
            temp += rem;
            ans.push_back(temp % 2  + '0');
            rem = temp / 2;
            i--;
            j--;
        }
        if(rem != 0) ans.push_back(rem + '0');
        reverse(ans.begin(), ans.end());
        return ans;   
    }
};