bool canConstruct(char* ransomNote, char* magazine) {
    if (ransomNote == NULL || magazine == NULL ) { return false; }
    if (*ransomNote == '\0' || *magazine == '\0') { return false; }

    uint16_t charCount[30] = {0x00};

    while (*magazine) {
        charCount[(unsigned char)*magazine - 0x61]++;
        magazine++;
    }

    while(*ransomNote) {
        if(charCount[(unsigned char)*ransomNote - 0x61] == 0) {
            return false;
        }
        charCount[(unsigned char)*ransomNote - 0x61]--;
        ransomNote++;
    }

    return true;
}
