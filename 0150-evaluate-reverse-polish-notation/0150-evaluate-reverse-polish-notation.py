class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        operator_map = {
            '+' : lambda a,b : a+b,
            '-' : lambda a,b : a-b,
            '*' : lambda a,b : a*b,
            '/' : lambda a,b : int(a/b)
        }

        for token in tokens:
            if token in operator_map:
                b,a = stack.pop(), stack.pop()
                stack.append(operator_map[token](a,b))
            else:
                stack.append(int(token))
        return stack[-1]
        
                    