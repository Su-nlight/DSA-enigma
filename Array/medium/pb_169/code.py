class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=0
        element=-1
        for i in nums:
            if count == 0: 
                count = 1
                element=i
            elif i==element: count+=1
            else: count-=1
        return element        