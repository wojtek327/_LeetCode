class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        arr = [] 

        for a, b in zip(word1, word2):
            arr += a
            arr += b

        arr += word1[len(word2):]
        arr += word2[len(word1):]

        return "".join(arr)