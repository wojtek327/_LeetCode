char *mergeAlternately(const char *word1, const char *word2) {
    uint8_t len1 = strlen(word1);
    uint8_t len2 = strlen(word2);
    char *result = malloc(len1 + len2 + 1);
    if (!result) { return NULL; }

    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t index = 0;
    while (i < len1 || j < len2) {
        if (i < len1) { result[index++] = word1[i++]; }
        if (j < len2) { result[index++] = word2[j++]; }
    }

    result[index] = '\0';
    return result;
}
