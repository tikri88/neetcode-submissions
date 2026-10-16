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

    ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
    {
        //Lists can be empty, handle this edge case
        if(!l1 && !l2)
            return nullptr;
        else if(!l1)
            return l2;
        else if(!l2)
            return l1;
        ListNode *head = nullptr;
        ListNode *ptr = nullptr;
        if(l1->val <= l2->val)
        {
            head = l1;
            ptr = head;
            l1 = l1->next;
            ptr->next = nullptr;
        }
        else
        {
            head = l2;
            ptr = head;
            l2= l2->next;
            ptr->next = nullptr;
        }
        while(l1 != nullptr && l2!= nullptr)
        {
            if(l1->val <= l2->val)
            {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;

            }
            else
            {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr)
            ptr->next = l1;
        if(l2 != nullptr)
            ptr->next = l2;
        return head;
    }


    ListNode* divideAndconquer(const vector<ListNode*>& lists, int start, int end)
    {
        //Best Case: Return if it is a single list
        if(start == end)
            return lists[start];
        int mid = start + (end-start)/2;
        ListNode* lMerge = divideAndconquer(lists, start, mid);
        ListNode* rMerge = divideAndconquer(lists, mid+1, end);
        return mergeTwoList(lMerge, rMerge);
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        ListNode *head = divideAndconquer(lists, 0, lists.size()-1);
        return head;
        
    }
};
