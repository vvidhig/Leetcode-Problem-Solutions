class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        curr1 = headA
        curr2 = headB
        s1 = set()
        while curr1 != None or curr2 != None:
            if curr1 != None:
                if curr1 not in s1:
                    s1.add(curr1)
                    curr1 = curr1.next
                else:
                    return curr1
            if curr2 != None:
                if curr2!=None and curr2 not in s1:
                    s1.add(curr2)
                    curr2 = curr2.next
                else:
                    return curr2
        return None

