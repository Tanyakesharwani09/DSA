class Node{
public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

    Node(int key1,int val1){
        key = key1;
        val = val1;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};
class List{
public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev =head;
        size =0;
    }
    void addfront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* prevnode = node->prev; 
        Node* nextnode = node->next; 
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        size--;
    }
};
class LFUCache {
    map<int, Node*> mpp;
    map<int, List*> freqListMap;
    int Capacity;
    int minfreq;
    int maxcachesize;
public:
    LFUCache(int capacity) {
        Capacity = capacity;
        maxcachesize = capacity;
        minfreq = 0;
    }
    void update(Node* node) {
    // Check if the current count exists in freqListMap
    if (freqListMap.find(node->cnt) != freqListMap.end()) {
        // Remove from freqListMap->List
        freqListMap[node->cnt]->removeNode(node);
        
        // If it was the last element with cnt = minfreq
        if (node->cnt == minfreq && freqListMap[node->cnt]->size == 0) {
            minfreq++;
        }
        // Increase frequency
        int newcnt = ++node->cnt;
        
        // Create new list with the given frequency
        List* newlist;
        if (freqListMap.find(newcnt) != freqListMap.end()) {
            newlist = freqListMap[newcnt];
        } else {
            newlist = new List();
            freqListMap[newcnt] = newlist;
        }
        
        // Add at front
        newlist->addfront(node);
    }
}
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        Node* node = mpp[key];
        update(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(maxcachesize == 0){
            return ;
        }
        //if key already exists
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            update(node);
        }
        else{
            //check if no space
            if(Capacity == 0){
                List* list = freqListMap[minfreq];
                if (list->size > 0) {
                    Node* lruNode = list->tail->prev;
                    list->removeNode(lruNode);
                    mpp.erase(lruNode->key);
                    Capacity++;
                    
                    if (list->size == 0) {
                        freqListMap.erase(minfreq);
                        minfreq++;
                    }
                }
            }
            //new node is being added
            minfreq=1;
            //create a new pointer of type List
            List* list = new List();
            //does it exists for cnt=1
            if(freqListMap.find(1) != freqListMap.end()){
                list = freqListMap[1];
            }
            else{
                freqListMap[1] = list;
            }
            Node* node = new Node(key,value);
            //add at front of list
            list->addfront(node);
            //add in mpp
            mpp[key] = node;
            Capacity--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */