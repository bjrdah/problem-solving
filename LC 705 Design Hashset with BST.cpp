/*https://leetcode.com/problems/design-hashset/description*/
class MyHashSet {
    struct Node{
        int value;
        Node* right;
        Node* left;
    };
    Node* root;
public:
    MyHashSet() {
        root=NULL;
    }
     Node* insertNode(Node* t,int key)
    {
        if(t == NULL)
        {
            t = new Node;
            t->value = key;
            t->left = t->right = NULL;
        }
        else if(key==t->value) return t;
        else if(key < t->value)
            t->left = insertNode(t->left,key);
        else if(key > t->value)
            t->right = insertNode(t->right,key);
        return t;
    }
      Node* findMin(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    Node* removeNode(int x, Node* t) {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->value)
            t->left = removeNode(x, t->left);
        else if(x > t->value)
            t->right = removeNode(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->value = temp->value;
            t->right = removeNode(t->value, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        return t;
    }
    bool exist(Node* t,int key){
        if(t==NULL) return false;
        if(t->value==key) return true;
        if(t->value>key) return exist(t->left,key);
        return exist(t->right,key);
    }
    void add(int key) {
        root=insertNode(root,key);
    }
    void remove(int key) {
        root=removeNode(key,root);
    }
    bool contains(int key) {
        return exist(root,key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
