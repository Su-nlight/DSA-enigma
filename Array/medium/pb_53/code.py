class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum= -10000
        temp=0
        for i in nums:
            temp+=i 
            sum = sum if sum > temp else temp
            temp = 0 if temp < 0 else temp
        return sum