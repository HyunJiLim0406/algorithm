class Solution:
    def __init__(self):
        self.result = set()

    def backtracking(self, target: int, candidates: List[int], arr: List[int], index: int):
        if sum(arr) == target:
            self.result.add(tuple(arr))
            return
        if sum(arr) > target or index == len(candidates) or sum(arr) + sum(candidates[index:]) < target:
            return
        
        nextArr = arr.copy()
        nextArr.append(candidates[index])
        self.backtracking(target, candidates, nextArr, index + 1)
        self.backtracking(target, candidates, arr, index + 1)
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.backtracking(target, sorted(candidates), [], 0)
        return self.result
        