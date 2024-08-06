class Solution(object):
    def reverseBetween(self, head, left, right):
        if left == right:
            return head
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        for _ in range(left - 1):
            prev = prev.next
        left1 = prev.next
        right1 = left1.next
        for _ in range(right - left):
            temp = right1.next
            right1.next = left1
            left1 = right1
            right1 = temp
        prev.next.next = right1
        prev.next = left1
        return dummy.next
