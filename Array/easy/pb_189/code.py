class Solution:
    @staticmethod
    def rev(arr, start, end)->List[int]:
        while(start < end):
            arr[start], arr[end] = arr[end], arr[start]
            start+=1
            end-=1
        return arr
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k=k%n
        if k==0: return
        nums=self.rev(nums, 0, n-1)
        nums=self.rev(nums, 0, k-1)
        nums=self.rev(nums, k, n-1)

        