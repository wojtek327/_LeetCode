class Solution:
    def getVal(self, c: str) -> int:
        match c:
            case 'I':
                return 1
            case 'V':
                return 5
            case 'X':
                return 10
            case 'L':
                return 50
            case 'C':
                return 100
            case 'D':
                return 500
            case 'M':
                return 1000
        return 0

    def romanToInt(self, s: str) -> int:
        summ = 0
        n = len(s)
        i = 0
        
        while i < n:
            if i < n - 1 and self.getVal(s[i]) < self.getVal(s[i+1]):
                summ += self.getVal(s[i+1]) - self.getVal(s[i])
                i += 2
            else:
                summ += self.getVal(s[i])
                i += 1
        
        return summ