class Solution:
    def __init__(self):
        self.result = []

    def backtracking(self, target: int, candidates: List[int], arr: List[int], index: int):
        if sum(arr) == target:
            self.result.append(arr)
            return
        if sum(arr) > target or index == len(candidates) or sum(arr) + sum(candidates[index:]) < target:
            return
        
        nextArr = arr.copy()
        nextArr.append(candidates[index])
        index += 1
        self.backtracking(target, candidates, nextArr, index)
        
        while index < len(candidates) and nextArr[-1] == candidates[index]:
            index += 1
        self.backtracking(target, candidates, arr, index)
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.backtracking(target, sorted(candidates), [], 0)
        return self.result