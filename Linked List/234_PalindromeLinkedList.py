class Solution(object):
    def reverse(self, head):
        prev = None
        curr = head
        while curr!=None:
            nex = curr.next
            curr.next = prev
            prev = curr
            curr = nex
        return prev

    def isPalindrome(self, head):
        h1 = head
        h2 = head
        while h2!=None and h2.next!=None:
            h1 = h1.next
            h2 = h2.next.next
        rev = self.reverse(h1)
        h = head
        while rev!=None:
            if h.val != rev.val:
                return False
            else:
                h = h.next
                rev = rev.next
        return True
