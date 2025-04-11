func lengthOfLongestSubstring(s string) int {
    var charIndexMap [256]int

    for i := range charIndexMap {
        charIndexMap[i] = -1
    }

    maxLength := 0
    startIndex := 0

    for i := 0; i < len(s); i++ {
        ch := s[i]
        if charIndexMap[ch] != -1 && charIndexMap[ch] >= startIndex {
            startIndex = charIndexMap[ch] + 1
        }

        charIndexMap[ch] = i

        if (i - startIndex + 1) > maxLength {
            maxLength = i - startIndex + 1
        }
    }

    return maxLength
}