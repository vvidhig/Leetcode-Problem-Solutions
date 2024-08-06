class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return head
        first = head
        second = head.next
        while second != None:
            temp = second.next
            second.next = first
            first = second
            second = temp
        head.next = None
        head = first
        return head
