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
        if x > y:
            string1, score1 = self.calculate(s, "ab", x)
            string2, score2 = self.calculate(string1, "ba", y)
            return score1 + score2
        else:
            string1, score1 = self.calculate(s, "ba", y)
            string2, score2 = self.calculate(string1, "ab", x)
            return score1 + score2