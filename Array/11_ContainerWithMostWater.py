class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        curr = 0
        maxi = -1
        while(left<=right):
            curr = (right - left) * min(height[left], height[right])
            maxi = max(maxi, curr)
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return maxi
