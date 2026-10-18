class LRUCache {
private:
    typedef struct node
    {
        int key;
        int value;
        struct node* previous;
        struct node* next;
        node(int key, int val): key(key), value(val), previous(nullptr), next(nullptr)
        {

        }
    } Node;
    int cap;
    int size;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> hm;
public:
    void addNodeAtTail(Node* tmp)
    {
        tail->previous->next = tmp;
        tmp->next = tail;
        tmp->previous = tail->previous;
        tail->previous = tmp;
    }

    void removeNode(Node* tmp)
    {
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
    }

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->previous = head;
    }
    
    int get(int key) {
        auto itr = hm.find(key);
        if(itr == hm.end())
            return -1;
        removeNode(itr->second);
        addNodeAtTail(itr->second);
        return itr->second->value;
    }
    
    void put(int key, int value) {
        auto itr = hm.find(key);
        //Case1(HIT case), if value is already present, it means we need to update this node value and change it's position so that it is mark as most recently used.
        //Case2(MISS Case), In this case before inserting, check if size==capacity, remove LRU node. add node now at tail
        if(itr != hm.end())
        {
            removeNode(itr->second);
            addNodeAtTail(itr->second);
            itr->second->value = value;
        }
        else
        {
            if(size == cap)
            {
                Node* tmp = head->next;
                removeNode(head->next);
                hm.erase(tmp->key);
                delete tmp;
                size--;
            }
            Node *tmp = new Node(key, value); 
            addNodeAtTail(tmp);
            hm.insert({key, tmp});
            size++;

        }
    }
    ~LRUCache()
    {
        Node* curr = head->next;
        while(curr != nullptr)
        {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
};
