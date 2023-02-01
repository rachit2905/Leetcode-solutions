class KthLargest {
public:
      int k;
public:
    vector<int> heapK;
    KthLargest(int k1, vector<int>& nums) {
        k = k1;
        int l = nums.size();
        heapK.push_back(-2147483648);
        //if I want to do this with a min heap of k largest elements
        //first I heapify the first k elements
        //and I treat the other elements as added elements.
        //first we put l numbers into heap
        int a;
        if(l < k)
        {
            a = l;
        }
        if(k <=l)
        {
            a = k;
        }
        for(int i=0;i<a;i++)
        {
            heapK.push_back(nums[i]);
        }
        //then heapify heapK
        //index is 1-a
        for(int i=a/2;i>0;i--)
        {
            while(2*i <= a)
            {
                if(2*i+1 <= a && heapK[i] > heapK[2*i+1] && heapK[2*i+1] < heapK[2*i])
                {
                    int temp = heapK[i];
                    heapK[i] = heapK[2*i+1];
                    heapK[2*i+1] = temp;
                    i = 2*i+1;
                }
                else if(heapK[i] > heapK[2*i])
                {
                    int temp = heapK[i];
                    heapK[i] = heapK[2*i];
                    heapK[2*i] = temp;
                    i = 2*i;
                }
                else
                {
                    break;
                }
            }
        }
        //then put the rest of the nums in
        for(int i=k;i<l;i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        int l = heapK.size()-1;
        if(l == 0)//if there is nothing
        {
            heapK.push_back(val);
            return val;
        }
        if(l == k){//if we already have k elements, we need to pop first
            if(heapK[1] >= val)
            {
                return heapK[1];
            }
            //now if the val is one of the K largest element
            //we pop min
            //we push val
            //pop
            heapK[1] = heapK[k];
            //percolate down
            int i=1;
            //we continue until it doesn't have child or it is smaller than both children
            //since we pop an element the index is 1-k-1
            while(2*i <= k-1)
            {
                //check if its smaller than any of its children
                if(2*i+1 <= k-1 && heapK[2*i+1] < heapK[2*i] && heapK[i] > heapK[2*i+1])
                {
                    int temp = heapK[i];
                    heapK[i] = heapK[2*i+1];
                    heapK[2*i+1] = temp;
                    i = 2*i+1;
                }
                else if(heapK[2*i] < heapK[i])
                {
                    int temp = heapK[i];
                    heapK[i] = heapK[2*i];
                    heapK[2*i] = temp;
                    i = 2*i;
                }
                else
                {
                    break;
                }
            }
            l--;//since we poped an val, the size decrease by 1
            //push val
        }
        else
        {
            heapK.push_back(0);
        }
        //push val
        heapK[l+1] = val;
        int i = l+1;
        //percolate up
        while(i/2 > 0 && heapK[i] < heapK[i/2])
        {
            int temp = heapK[i/2];
            heapK[i/2] = heapK[i];
            heapK[i] = temp;
            i/=2;
        }
        return heapK[1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */