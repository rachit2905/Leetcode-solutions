class Solution {
public:
    int tribonacci(int n) {
        int x=0,y=1,z=1;
        if(n<3)
        {
            if(n<=1)return n;
            else return 1;
        }
        int temp=0;
        for(int i=3;i<=n;i++)
        {
            temp=x+y+z;
            x=y;
            y=z;
            z=temp;
        }
        return temp;
    }
};