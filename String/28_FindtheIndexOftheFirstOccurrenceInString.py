class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if haystack == needle:
            return 0
        if len(needle) == 1 and needle in haystack:
            return haystack.index(needle)
        l1 = len(haystack)
        l2 = len(needle)
        for i in range(l1-l2+1):
            s1 = haystack[i:l2+i]
            print(s1)
            if s1 == needle:
                return i
        return -1
