class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for i in range(len(nums)):
            j = i+1
            k = len(nums)-1
            while j<k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    lis = [nums[i], nums[j], nums[k]]
                    if lis not in res:
                        res.append(lis)
                    j+=1
                    k-=1
                elif sum < 0:
                    j+=1
                else:
                    k-=1
        return res
