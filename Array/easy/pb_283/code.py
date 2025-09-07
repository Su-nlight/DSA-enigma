class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j=-1
        for k in range(len(nums)):
            if(nums[k]==0): 
                j=k
                break
        if j==-1 or len(nums) in [0,1]: return
        for i in range(j+1, len(nums)):
            if nums[i]!=0: 
                nums[j],nums[i]=nums[i],nums[j]
                j+=1
            

        