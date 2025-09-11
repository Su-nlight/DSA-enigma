class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        din={}
        for i,n in enumerate(nums):
            comp=target-n
            if comp in din:
                return [din[comp],i]
            din[n]=i
        return []