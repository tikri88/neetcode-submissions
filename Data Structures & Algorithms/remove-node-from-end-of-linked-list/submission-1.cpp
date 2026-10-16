/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /**
            Trick here is that you can not traverse back from end of the list. Clue is, is there any way to calculate the position from beginning.
            So idea is, nth from end is total-n+1 from beginning.
            
        **/
        //Insert a dummy node to handle first node deletion scenario
        ListNode *dummy_node = new ListNode(INT_MAX);
        dummy_node->next = head;
        //Count total node in list
        size_t count = 0;
        ListNode* ptr = head;
        while(ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
        size_t pos_from_beg = count - n + 1;
        int track_node_count = 0;
        //Reinitalise to head to position the pointer just before the node which we need to delete
        ptr = dummy_node;
        while((track_node_count+1) < pos_from_beg)
        {
            track_node_count += 1;
            ptr = ptr->next;
            
        }
        //We have already made sure that tmp will point to valid location in our above loop logic

        ListNode *tmp = ptr->next;
        if(head == tmp)
            head = head->next;
        ptr->next = ptr->next->next;
        delete tmp;
        delete dummy_node;
        return head;
        
    }
};
