class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 3 and (s[0] == s[2]):
            return True
        i = 0
        j = len(s)-1
        while i<j:
            if s[i] != s[j]:
                s1 = s[:i]+s[i+1:]
                s2 = s[:j]+s[j+1:]
                return s1==s1[::-1] or s2 == s2[::-1]
            i+=1
            j-=1
        return True
