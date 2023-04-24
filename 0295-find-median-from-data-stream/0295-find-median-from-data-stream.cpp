class MedianFinder {
public:
    priority_queue<int>q1;
    priority_queue<int, vector<int>, greater<int>>q2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q1.size()==0){q1.push(num);return;}
        else if(num<=q1.top())
        {
           q1.push(num);
        }
        else if(num>q1.top())
            q2.push(num);
        if((q1.size()+q2.size())%2)
        {
            if(q1.size()<q2.size()){
                int x=q2.top();
                q1.push(x);
                q2.pop();
            }
        }
        else
        {
            if(q1.size()>q2.size())
            {
                int x=q1.top();
                q2.push(x);
                q1.pop();
            }
            else if(q2.size()>q1.size())
            {
               int x=q2.top();
                q1.push(x);
                q2.pop();
            }
        }
    }
    
    double findMedian() {
        if((q1.size()+q2.size())%2)
            return q1.top();
        else
        {
            return (q1.top()+q2.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */