class LRUCache {
public:
    class node{ //doubly linked list
        public:
        node* next;
        node* prev;
        int key;
        int val;

        node(int key1, int val1){
            key = key1;
            val = val1;
        }
    };

    int cap;
    unordered_map<int,node*> mp;

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    void addNode(node* temp){ //adding back means this key is recently used, hence we keep right in front of the head.
                              
        node* res = head->next;

        head->next = temp;
        res->prev = temp;
        temp->prev = head;
        temp->next = res;
    }                        

    void deleteNode(node* temp){ 

        node* front = temp->next;
        node* back = temp->prev;

        front->prev = back;
        back->next = front;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail; //very important to connect the head and tail at initiation
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{

            node* curr = mp[key];
            deleteNode(curr);
            addNode(curr);

            return curr->val;
        }
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            node* curr = mp[key];
            curr->val = value;

            deleteNode(curr);
            addNode(curr);
        }
        else{
            if(mp.size()==cap){
                node* res = tail->prev; //since recently used nodes get added in front of the head, the least recently used is at the end of that list ie just before the tail
                mp.erase(res->key);
                deleteNode(res);
            }
            node* newNode = new node(key,value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */