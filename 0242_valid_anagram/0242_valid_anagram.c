bool isAnagram(char* s, char* t) {
    if (s == NULL || t == NULL ) { return false; }
    if (*s == '\0' || *t == '\0') { return false; }

    if(strlen(t) < strlen(s)) {
        return false;
    }

    uint16_t charCount[30] = {0x00};

    while (*s) {
        charCount[(unsigned char)*s - 0x61]++;
        s++;
    }

    while(*t) {
        if(charCount[(unsigned char)*t - 0x61] == 0) {
            return false;
        }
        charCount[(unsigned char)*t - 0x61]--;
        t++;
    }

    return true;
}
