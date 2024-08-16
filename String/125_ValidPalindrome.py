class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s1 = [x for x in s if x.isalnum()]
        s2 = "".join(s1)
        s2 = s2.lower()
        if s2 == "" or len(s2)==1:
            return True
        i = 0
        j = len(s2)-1
        cnt=0
        while i<j:
            if s2[i]==s2[j]:
                cnt+=1
            else:
                return False
            i+=1
            j-=1
        if cnt > 0:
            return True
