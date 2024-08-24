from functools import reduce
import operator

class Solution:
    def fractionList(self, expression):
        result = []
        sign = expression[0]
        num1 = ''
        num2 = ''
        isDivider = False

        for char in expression[1:]:
            if char in ('+', '-'):
                result.append([sign, int(num1), int(num2)])
                sign = char
                num1 = ''
                num2 = ''
                isDivider = False
            if char.isdigit():
                if not isDivider:
                    num1 += char
                else:
                    num2 += char
            if char == '/':
                isDivider = True
        return result
    
    def calculate(self, fraction: list, denominator: int):
        result = 0
        for item in fraction:
            num = item[1] * int((denominator / item[2]))
            if item[0] == '+':
                result += num
            elif item[0] == '-':
                result -= num
        return result

    def irreducible(self, numerator: int, denominator: int):
        isPlus = True
        if numerator < 0:
            isPlus = False
            numerator = -numerator
        
        index = 2
        while index <= min(numerator, denominator):
            if numerator % index == 0 and denominator % index == 0:
                numerator /= index
                denominator /= index
                index = 2
            else:
                index += 1

        if isPlus:
            return int(numerator), int(denominator)
        else :
            return -int(numerator), int(denominator)

    def fractionAddition(self, expression: str) -> str:
        if expression[0].isdigit():
            expression = '+' + expression
        expression += '+'

        fraction = self.fractionList(expression)
        denominator = reduce(operator.mul, [item[2] for item in fraction])
        numerator = self.calculate(fraction, denominator)

        if numerator == 0:
            return '0/1'
        else:
            n, d = self.irreducible(numerator, denominator)
            return str(n) + '/' + str(d)
        