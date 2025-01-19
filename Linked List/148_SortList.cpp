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
    ListNode* merge(ListNode* headA, ListNode* headB)
    {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val < temp2->val)
            {
                curr->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                curr->next = temp2;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        if(temp1!=NULL)
        {
            curr->next = temp1;
        }
        if(temp2!=NULL)
        {
            curr->next = temp2;
        }
        return dummy->next;
    }
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* left = head;
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};
