class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []

        for item in s:
            if item == '(' or not stack:
                stack.append(item)
            elif item == ')' and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(item)
        return len(stack)
        