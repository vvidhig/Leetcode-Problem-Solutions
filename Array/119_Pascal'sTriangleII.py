class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]

        lis = self.getPascal(rowIndex+1)
        for i in lis:
            lis1 = i
        return lis1

    def getPascal(self, num):
        if num == 0:
            return []
        if num == 1:
            return [1]
        
        prev = self.getPascal(num-1)
        numrow = [1]*num

        for i in range(1, num-1):
            numrow[i] = prev[-1][i-1] + prev[-1][i]

        prev.append(numrow)
        return prev   
