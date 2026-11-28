class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        def do_op(a,b,operator):
            match operator:
                case '+':
                    return a+b
                case '-':
                    return a-b
                case '*':
                    return a*b
                case '/':
                    return int(a/b)
        operators = set(['+','-','/','*'])
        for token in tokens:
            if token in operators:
                b,a = stack.pop(), stack.pop()
                stack.append(do_op(a,b,token))
            else:
                stack.append(int(token))
        return stack[-1]
        
                    