class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: ListNode
        :rtype: int
        """
        dummy = ListNode(0)
        dummy.next = head
        num = -1
        while dummy!=None:
            dummy = dummy.next
            num+=1
        curr = head
        sum1 = 0
        while curr!=None:
            sum1 += curr.val * (2**(num-1))
            num -= 1
            curr = curr.next
        
        return sum1
