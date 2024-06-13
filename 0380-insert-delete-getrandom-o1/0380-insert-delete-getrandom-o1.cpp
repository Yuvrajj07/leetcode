class RandomizedSet {
public:
    RandomizedSet() {
      
    }
     bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        m[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        int last = values.back();
        m[last] = it->second;
        values[it->second] = last;
        values.pop_back();
        m.erase(it);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % values.size();
        return values[idx];
    }

private:
    unordered_map<int, int> m;
    vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */