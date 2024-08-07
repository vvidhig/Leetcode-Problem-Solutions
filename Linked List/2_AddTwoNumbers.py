class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head1 = l1
        head2 = l2
        sum2 = 0
        ret_list = ListNode(0)
        dummy = ret_list
        while head1!=None or head2!=None or sum2!=0:
            val1 = head1.val if head1!=None else 0
            val2 = head2.val if head2!=None else 0
            sum1 = sum2 + val1 + val2
            sum2 = int(sum1/10)
            place = sum1%10
            node = ListNode(place)
            ret_list.next = node
            ret_list = node
            head1 = head1.next if head1!=None else None
            head2 = head2.next if head2!=None else None
        return dummy.next
