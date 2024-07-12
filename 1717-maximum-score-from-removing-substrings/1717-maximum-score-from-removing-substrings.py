class Solution:
    def calculate(self, string: str, key: str, point: int):
        score = 0
        stack = []
        for s in string:
            if len(stack) > 0:
                pop = stack.pop()
                if pop + s == key:
                    score += point
                    continue
                stack.append(pop)
            stack.append(s)
        return ''.join(stack), score

    def maximumGain(self, s: str, x: int, y: int) -> int:
        x_str, y_str = "ab", "ba"
        if x < y:
            x_str, y_str = "ba", "ab"
            x, y = y, x
        string1, score1 = self.calculate(s, x_str, x)
        string2, score2 = self.calculate(string1, y_str, y)
        return score1 + score2
        