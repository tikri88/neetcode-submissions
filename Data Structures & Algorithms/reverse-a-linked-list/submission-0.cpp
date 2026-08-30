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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
        {
            return head;
        }
        ListNode *prevPtr = head, *currPtr=head->next;
        while(currPtr != nullptr)
        {
            ListNode *tmp = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = tmp;
        }
        head->next = nullptr;
        return prevPtr;
    }
};
