/* https://leetcode.com/problems/design-hashmap/description/ */
class MyHashMap {
public:
    int HashMap[1000001];
    MyHashMap() {
        fill(HashMap, HashMap + 1000001, -1);
    }
    void put(int key, int val) {
        HashMap[key] = val;
    }
    int get(int key) {
        return HashMap[key];
    }
    void remove(int key) {
        HashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
