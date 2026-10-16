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
    void reorderList(ListNode* head) {
        //First find the middle node address and then reverse second half of linked list and then iterate both the list and adjust addresses accordingly
        if(head->next == nullptr)
        {
            return;
        }
        ListNode *slow = head, *fast = head;
        ListNode *tmp = nullptr;
        while(fast && fast->next != nullptr)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //Terminate first list so that last node does point to null
        tmp->next = nullptr;
        //Now slow will point to middle of the linked list. Reverse List now
        ListNode* current = slow->next;
        ListNode* previous = slow;
        while(current)
        {
            ListNode* tmp = current->next;
            current->next = previous;
            previous = current;
            current = tmp;
        }
        slow->next = nullptr;
        // Now we have 2 lists, one pointed by head and other pointed by previous pointer. Need to shuffle the pointers to get desired order.
        ListNode *p1 = head, *p2=previous;
        while(p1 && p2)
        {
            ListNode* p1_tmp = p1->next;
            ListNode *p2_tmp = p2->next;
            p1->next = p2;
            if(p1_tmp != nullptr)
                p2->next = p1_tmp;
            p1 = p1_tmp;
            p2 = p2_tmp;
        }
    }
};
