class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_array = list(str(x))
        x_array_reverse = list(str(x))

        x_array_reverse.reverse()

        if x_array == x_array_reverse:
            return True
        return False
        