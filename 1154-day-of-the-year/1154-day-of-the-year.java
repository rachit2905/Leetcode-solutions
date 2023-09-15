class Solution {
    public int dayOfYear(String date) {
        String[] s = date.split("-", 3);
        int y=Integer.parseInt(s[0]);  
        int m=Integer.parseInt(s[1]);  
        int d=Integer.parseInt(s[2]);  
        int ans=0;
        int[] arr={31,28,31,30,31,30,31,31,30,31,30,31};
        //add days of all month before current month
        for(int i=0;i<m-1;i++)
        {
            ans+=arr[i];
        }
        if((y%4==0)&&(y%100!=0)||(y%400==0))
        {
            //if it is leap year and month is march or above add 1
            if(m>2)
                ans+=1;
        }
        //add days of current month
        return ans+d;
    }
}