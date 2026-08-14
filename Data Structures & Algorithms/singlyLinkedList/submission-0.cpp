class LinkedList {
public:
    LinkedList() {

    }

    int get(int index) {
        if(index >= count)
            return -1;
        List *itr = head;
        int i = 0;
        while(i != index)
        {
            i++;
            itr = itr->next;
        }
        return itr->data;
    }

    void insertHead(int val) {
        count = count+1;
        List *newNode = new List(val);
        if(head == nullptr)
        {
            head = newNode;
            List *ptr = head;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void insertTail(int val) {
        count = count+1;
        List *newNode = new List(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        List *itr = head;
        while(itr->next != nullptr)
        {
            itr = itr->next;
        }
        itr->next = newNode;
    }

    bool remove(int index) {

        if(index >= count)
        {
            return false;
        }
        if(index == 0)
        {
            List *tmp = head;
            head = head->next;
            delete tmp;
            count = count - 1;
            return true;
        }
        int i =1;
        List *itr = head;
        while(i < index)
        {
            itr = itr->next;
            i++;
        }
        List *tmp = itr->next;
        itr->next = itr->next->next;
        delete tmp;
        count = count - 1;
        return true; 
    }

    vector<int> getValues() {
        vector<int> listValues;
        List *itr = head;
        while(itr != nullptr)
        {
            listValues.push_back(itr->data);
            itr = itr->next;
        }
        return listValues;
    }
private:
    struct List
    {
        int data;
        struct List *next;
        List()
        {
            next = nullptr;
        }
        List(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    }*head = nullptr;
    int count = 0;
};
