class MyHashMap {
public:
    map<int,int>m1;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        m1[key]=value;
    }
    
    int get(int key) {
        if(m1.find(key)!=m1.end())
        return m1[key];
        return -1;
    }
    
    void remove(int key) {
          if(m1.find(key)!=m1.end())
        m1.erase(m1.find(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */