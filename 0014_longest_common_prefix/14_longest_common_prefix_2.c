char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) { return ""; }

    int len = 0;
    int minLen = strlen(strs[0]);
    char* prefix = strs[0];

    //Looking for smallest string in array
    for (int i = 1; i < strsSize; i++) {
        minLen = strlen(strs[i]) < minLen ? strlen(strs[i]) : minLen;
    }

    for (int c = 0; c < minLen; ++c) {
        for (int s = 1; s < strsSize; ++s) {
            if (strs[s][c] != strs[0][c]) {
                prefix[len] = '\0';
                return prefix;
            }
        }
        ++len;
    }

    prefix[len] = '\0';
    return prefix;
}
