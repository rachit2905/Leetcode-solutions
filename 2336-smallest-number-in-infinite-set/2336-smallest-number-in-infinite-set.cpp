class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>q1;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            q1.push(i);
    }
    
    int popSmallest() {
        int x=q1.top();
        q1.pop();
        return x;
    }
    
    void addBack(int num) {
         stack<int>s1;
         
         while(q1.size()>0)
         {
             if(q1.top()!=num)
             {
                 s1.push(q1.top());
                 q1.pop();
             }
             else
             {
                
                 break;
             }
            
         }
        if(q1.size()==0)
        {
            s1.push(num);
        }
        while(!s1.empty())
        {
            q1.push(s1.top());
            s1.pop();
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */