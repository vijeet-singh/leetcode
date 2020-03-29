class RandomizedSet {
    unordered_set<int> bag;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //unordered_set<int> bag;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(bag.find(val) == bag.end()) {
            bag.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(bag.find(val) != bag.end()){
            bag.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%bag.size();
        auto it = bag.begin();
        std::advance(it,r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
