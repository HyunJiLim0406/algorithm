class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stack = []
        for op in logs:
            if op == '../':
                if stack:
                    stack.pop()
            elif op == './':
                continue
            else:
                stack.append(op)
        return len(stack)
        