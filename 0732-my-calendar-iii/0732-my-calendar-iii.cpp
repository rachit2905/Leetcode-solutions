class MyCalendarThree {
public:
     map<int,int>mp;  
    int maxcount = 0;  
    MyCalendarThree() 
    {
        
    }
    
    int book(int start, int end) 
    {
       int count = 0;         mp[start]++; 
        mp[end]--; 
        for(auto it = mp.begin() ;it != mp.end() ; it++)
        {
            count = count + it->second;    
            maxcount = max(maxcount,count); 
        }
        return maxcount; 
        
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */