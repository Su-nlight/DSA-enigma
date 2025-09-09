class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        x1=0
        for i in range(len(nums)):
            x1=x1^nums[i]^(i+1)
        return x1
        