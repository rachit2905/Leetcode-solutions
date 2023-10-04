struct KeyValue {
    int key;
    int value;

public:
    KeyValue(int _key, int _value):key(_key), value(_value) {}
};


class MyHashMap {

    vector<list<KeyValue>> bucket;
    int bucketSize; 

    list<KeyValue>::iterator find(int key)
    {
        int index = hash(key);
        for(auto iter = bucket[index].begin(); iter != bucket[index].end(); iter++)
        {
            if(iter->key == key)
                return iter;
        }
        return bucket[index].end();
    }

    int hash(int key)
    {
        return  key% bucketSize;
    }

public:
    MyHashMap() {
        bucketSize = 10007;
        bucket.resize(bucketSize);
    }
    
    void put(int key, int value) {
        
        auto iter = find(key);
        int index = hash(key);
        if(iter != bucket[index].end())
        {
            iter->value = value;
            return;
        }
        bucket[index].push_back(KeyValue(key, value));
    }
    
    int get(int key) {
        auto iter = find(key);
        int index = hash(key);
        if(iter != bucket[index].end())
            return iter->value;
        return -1;
    }
    
    void remove(int key) {
        
        auto iter = find(key);
        int index = hash(key);
        if(iter != bucket[index].end())
            bucket[index].erase(iter);;

    }
};