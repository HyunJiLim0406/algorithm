from functools import cmp_to_key

class Solution:
    def compare(x, y):
        if str(x) + str(y) > str(y) + str(x):
            return -1
        else:
            return 1

    def largestNumber(self, nums: List[int]) -> str:
        result = sorted(nums, key = cmp_to_key(Solution.compare))
        return ''.join(map(str, result))
        