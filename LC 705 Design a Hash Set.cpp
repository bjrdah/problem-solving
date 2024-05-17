/* https://leetcode.com/problems/design-hashset/ */
class MyHashSet {
public:
    int hashSet[1000001];
    MyHashSet() {
        fill(hashSet,hashSet+1000001,-1);
    }
    
    void add(int key) {
        hashSet[key]=key;
    }
    
    void remove(int key) {
        hashSet[key]=-1;
    }
    
    bool contains(int key) {
        return hashSet[key]==key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
