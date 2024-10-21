class Solution:
    def calculate(self, chars: List[str], op: str):
        if op == '!':
            return 'f' if chars[0] == 't' else 't'
        elif op == '&':
            return 'f' if 'f' in chars else 't'
        elif op == '|':
            return 't' if 't' in chars else 'f'

    def parseBoolExpr(self, expression: str) -> bool:
        stack = []

        for exp in expression:
            if exp != ')':
                stack.append(exp)
                continue
            chars = []
            while stack:
                char = stack.pop()
                if char == '(':
                    break
                if char != ',':
                    chars.append(char)
            result = self.calculate(chars, stack.pop())
            stack.append(result)
            
        return False if stack.pop() == 'f' else True
        