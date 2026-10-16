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

    ListNode* reverseLwithKsize(ListNode*head, int g, int total_iteration)
    {
        if(total_iteration == 0 || head == nullptr)
            return head;
        
        ListNode *prev = nullptr, *curr = head, *nextPtr = nullptr;
        int k = g;
        while(curr != nullptr && k--)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        head->next = reverseLwithKsize(curr, g, total_iteration-1);
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //count total nodes
        ListNode* ptr = head;
        int count = 0;
        while(ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }

        ListNode *modified_list = reverseLwithKsize(head, k, count/k);
        return modified_list;
    }
};
