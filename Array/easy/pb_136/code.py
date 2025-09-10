from functools import reduce
from operator import ixor
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        x1 = reduce(ixor, nums, 0)
        return x1
        