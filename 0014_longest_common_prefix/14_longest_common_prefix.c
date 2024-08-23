char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) { return ""; }
    if (strsSize == 1) { return strs[0]; }

    int len = 0;
    int minLen = strlen(strs[0]);

    //Looking for smallest string in array
    for (int i = 1; i < strsSize; i++) {
        minLen = strlen(strs[i]) < minLen ? strlen(strs[i]) : minLen;
    }

    uint8_t breakFlag = 0;
    for (int c = 0; c < minLen; ++c) {
        char currentChar = strs[0][c];
        for (int s = 1; s < strsSize; ++s) {
            if (strs[s][c] != currentChar) {
                breakFlag = 1;
                break;
            }
        }
        if(breakFlag == 1) {
            break;
        }
        ++len;
    }

    if (len > 0) {
        char* ret = malloc((len + 1) * sizeof(char));

        if (ret == NULL) {
            return "";
        }

        strncpy(ret, strs[0], len);
        ret[len] = '\0';

        return ret;
    }

    return "";
}
