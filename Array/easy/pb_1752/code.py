class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n=len(nums)
        if n==0 or n==1:
            return True
        flag=0
        for i in range(n):
            if nums[i]>nums[(i+1)%n]:
                flag+=1
        return flag<=1
        