class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count=0
        max_cnt=0
        for i in nums:
            count = count+1 if i==1 else 0
            if max_cnt<count: max_cnt=count
        return max_cnt