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
private:
    // Helper function to reverse k nodes
    ListNode* reverseList(ListNode* head, int k) 
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        
        int count = 0;
        while (curr && count < k) 
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        // The original head is now the tail, so connect it to the remaining part
        head->next = nextNode;

        return prev; // New head of the reversed segment
    }

    // Helper function to get list length
    int listLength(ListNode* node) 
    {
        int len = 0;
        while (node) 
        {
            node = node->next;
            len++;
        }
        return len;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || k == 1) return head; // Edge case

        int n = listLength(head);
        int remain = n % k;
        int nodecount = 0;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        while (nodecount != (n - remain)) 
        {
            ListNode* segmentHead = curr;
            ListNode* newSegmentHead = reverseList(segmentHead, k);
            prevGroupEnd->next = newSegmentHead;
            prevGroupEnd = segmentHead; // The original head becomes the new tail
            
            nodecount += k;
            curr = prevGroupEnd->next;
        }

        return dummy->next;
    }
};

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
private:
    ListNode* reverseList(ListNode* head, int k)
    {
        if (!head) {
            return head;
        }
        ListNode* prev;
        ListNode* temp;
        ListNode* curr;
        ListNode* nextNode;
        prev = head;
        nextNode = prev->next;
        curr = prev->next;
        while(nextNode && --k)
        {
            nextNode = nextNode->next;
            curr->next = prev;
            if(prev == head)
            {
                prev->next = NULL;
            }
            prev = curr;
            curr = nextNode;
        }
        temp = prev;
        if(nextNode)
        {
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = nextNode;
        }
        return prev;
    }
    int listLength(ListNode* node)
    {
        int len = 0;
        while(node)
        {
            node = node->next;
            len += 1;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k==1)
        {
            return head;
        }
        int n = listLength(head);
        int remain = n % k;
        int nodecount = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp && nodecount != (n-remain))
        {
            temp->next = reverseList(temp->next, k);
            int i = 0;
            while(temp && i!=k)
            {
                temp = temp->next;
                i += 1;
            }
            nodecount += k;
        }
        return dummy->next;
    }
};
