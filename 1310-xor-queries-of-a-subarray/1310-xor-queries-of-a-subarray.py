from itertools import accumulate
from operator import xor

class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        sums = list(accumulate(arr, xor))
        result = []
        for left, right in queries:
            if left == 0:
                result.append(sums[right])
            else:
                result.append(sums[right] ^ sums[left - 1])
        return result
        