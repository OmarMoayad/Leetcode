class LRUCache {
public:
    int capacity;
    list<pair<int , int>> dll; 
    unordered_map<int, list<pair<int , int>>::iterator> umap; 

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end()) {
            return -1;
        }
        dll.splice(dll.begin(), dll, umap[key]);
        return umap[key]->second;
    }
    
    void put(int key, int value) {
        if (umap.find(key) != umap.end()) {
            umap[key]->second = value;
            dll.splice(dll.begin(), dll, umap[key]);
        } else {
            if ((int)dll.size() == capacity) {
                int keyToRemove = dll.back().first;
                dll.pop_back();
                umap.erase(keyToRemove);
            }
            dll.emplace_front(key, value);
            umap[key] = dll.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */