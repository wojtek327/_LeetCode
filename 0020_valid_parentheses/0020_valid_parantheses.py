class Solution:
    def isValid(self, s: str) -> bool:
        opcl = dict(('()', '[]', '{}'))
        stack = []
        
        for idx in s:
            if idx in '([{':
                stack.append(idx)
            elif len(stack) == 0 or idx != opcl[stack.pop()]:
                return False
                
        return len(stack) == 0