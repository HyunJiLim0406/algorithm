class Solution:
    def minOperations(self, logs: List[str]) -> int:
        count = 0
        for op in logs:
            if op == '../':
                count = max(count - 1, 0)
            elif op == './':
                continue
            else:
                count += 1
        return count
        