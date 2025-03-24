int lengthOfLongestSubstring(char* s) {
    if(s == NULL) { return 0; }
    if(s == '/0') { return 0; }

    int charIndexMap[256];
    memset(charIndexMap, -1, sizeof(charIndexMap));

    int maxLength = 0;
    int startIndex = 0;
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        // If the character is already in the map and its index is after the start index of the current substring,
        // update the start index to the index after the last occurrence of the character
        if (charIndexMap[s[i]] != -1 && charIndexMap[s[i]] >= startIndex) {
            startIndex = charIndexMap[s[i]] + 1;
        }
        
        charIndexMap[s[i]] = i;
        
        if (i - startIndex + 1 > maxLength) {
            maxLength = i - startIndex + 1;
        }
    }
    
    return maxLength;
}