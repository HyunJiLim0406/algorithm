class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        total = (len(rolls) + n) * mean
        target = total - sum(rolls)

        base = target // n
        if base <= 0:
            return []
        result = [base] * n
        target -= base * n
        for i in range(len(result)):
            extra = min(6 - result[i], target)
            result[i] += extra
            target -= extra
        if target != 0:
            return []
        return result
        