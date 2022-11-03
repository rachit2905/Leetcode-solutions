class Solution {
public:
    int longestPalindrome(vector<string>& arr) {
        unordered_map<string , int>mp1;   //map for first character and second character different
        unordered_map<string, int>mp2 ;  //map for first character and second character same
        int ans = 0 ;
        for(int i = 0 ; i < arr.size() ; i ++)
        {
            if(arr[i][0] == arr[i][1])
                mp2[arr[i]]++;
            else
                mp1[arr[i]]++;
        }
      for(auto i:mp1){
            string s=i.first;
            reverse(s.begin(),s.end());
           if(mp1.find(s)!=mp1.end()){
                ans+=min(mp1[i.first],mp1[s])*4;
		        mp1.erase(s);
            
            }
        }
        
        for(auto it : mp2)
        {
            if(it.second % 2 == 0)
            {
                ans += it.second * 2 ;
            mp2[it.first] = 0 ;
            }
        }
        
         
       int max1=0;
        //find max odd frequency
        for(auto i:mp2){
            if(i.second%2)
                max1=max(max1,i.second);
        }
        for(auto i:mp2){
            if(i.second==max1){
                ans += i.second*2;
                mp2[i.first]=0;
                break;
            }
        }
        
            for(auto i:mp2){
            if(i.second)
                ans +=2*(i.second-1);
           }
        
        
        
      return ans;  
        
    }
};