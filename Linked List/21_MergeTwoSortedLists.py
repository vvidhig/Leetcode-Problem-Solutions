# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        list1 = list1
        list2 = list2
        temp_list = ListNode()
        return_list = temp_list
        while list1 != None or list2 != None:
            if list1 != None and list2 != None:
                if list1.val < list2.val:
                    temp_list.next = ListNode(val = list1.val)
                    list1 = list1.next
                else:
                    temp_list.next = ListNode(val = list2.val)
                    list2 = list2.next
            elif list1 != None:
                temp_list.next = ListNode(val = list1.val)
                list1 = list1.next
            elif list2 != None:
                temp_list.next = ListNode(val = list2.val)
                list2 = list2.next
            temp_list = temp_list.next
        return return_list.next
