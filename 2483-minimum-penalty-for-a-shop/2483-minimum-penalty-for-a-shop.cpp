class Solution {
public:
    int bestClosingTime(string c) {
        int y = 0,n = 0;
        for(auto x:c){
            if(x=='Y')y+=1;
            else n+=1;
        }
        // when shop always open then penalty will be no. of n's
        // then we see from the (c.length()-1) index of the array that shop will closed after this hour 
        int ans1 = n,x = 0,ans = c.length();
        int t = y;
        for(int i = c.length()-1;i>=0;--i){
            if(c[i]=='Y'){
                t -= 1;
            }
            else n -= 1;
            x = n + (y - t); // this is the penalty
            if(ans1>=x){
                ans1 = x;
                ans = i;
            }
        }
        return ans;
    }
};