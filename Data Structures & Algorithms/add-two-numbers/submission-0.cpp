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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Reverse both the lists
        ListNode* m1 = l1;
        ListNode* m2 = l2;
        int sizeL1 = 0;
        int sizeL2 = 0;
        while(m1 != nullptr)
        {
            sizeL1++;
            m1 = m1->next;
        }
        while(m2 != nullptr)
        {
            sizeL2++;
            m2 = m2->next;
        }
        m1 = l1;
        m2 = l2;
        if(sizeL2 > sizeL1)
        {
            int diff = sizeL2-sizeL1;
            ListNode* ptr = m1;
            while(ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            int c = 0;
            while(c < diff)
            {
                ListNode* tmp = new ListNode(0);
                ptr->next = tmp;
                ptr = ptr->next;
                c++;
            }
        }
        else if(sizeL1 > sizeL2)
        {

            int diff = sizeL1-sizeL2;
            ListNode* ptr = m2;
            while(ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            int c = 0;
            while(c < diff)
            {
                ListNode* tmp = new ListNode(0);
                ptr->next = tmp;
                ptr = ptr->next;
                c++;
            }
        }
        int sum=0, carry=0;
        ListNode* head = nullptr, *ptr = nullptr;
        while(m1 != nullptr && m2 != nullptr)
        {
            sum = carry + m1->val + m2->val;
            carry = sum/10;
            int digit = sum%10;
            ListNode* tmp = new ListNode(digit);
            if(head == nullptr)
            {
                head = tmp;
                ptr = head;
            }
            else
            {
                ptr->next = tmp;
                ptr = ptr->next;
            }
            m1 = m1->next;
            m2 = m2->next;
        }
        if(carry)
        {
            ListNode* tmp = new ListNode(carry);
            ptr->next = tmp;
            ptr = ptr->next; 
        }
        return head;
        
    }
};
