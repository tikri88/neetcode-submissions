/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /** Approach- while creating node, save corresponding node in hash map. in second iteration of connecting random pointer just get the corresponding node from hashmap and connect
        **/

        Node *ptr = head;
        std::unordered_map<Node*, Node*> um;
        Node *tail = nullptr, *head2= nullptr;
        while(ptr != nullptr)
        {
            Node *tmp = new Node(ptr->val);
            if(head2 == nullptr)
            {
                head2 = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tmp;
            }
            um.insert({ptr, tmp});
            ptr = ptr->next;
        }
        //just checl
        //Now connect random pointer in new list
        Node *ptr1 = head;
        Node *ptr2= head2;
        while(ptr1 != nullptr)
        {
            Node *random_ptr = ptr1->random;
            auto itr = um.find(random_ptr);
            if(itr != um.end())
            {
                ptr2->random = itr->second;
            }
            else
            {
                ptr2->random = nullptr;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return head2;
    }
};
