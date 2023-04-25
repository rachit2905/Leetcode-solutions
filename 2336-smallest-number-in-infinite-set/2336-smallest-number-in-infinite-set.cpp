class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int store[1001];  // all ele initilased to 0

    SmallestInfiniteSet() {
        
        for(int i=1;i<=1000;i++)
        {
            pq.push(i);
            store[i]=1; // 1 signifies ele is present
        }
     
    }
    
    int popSmallest() {
       int ele=pq.top();
        pq.pop();
        store[ele]=0; //0 signifies ele nahi hai kyuki mene pop kiya

        return ele;
        
    }
    
    void addBack(int num) {
        if(store[num]==1)
        return;

        else // store[num]==0 , matlab number nhi hai
        {
            store[num]=1;
            pq.push(num);
        }
       
    }
};