bool isConsistent(unsigned int allowedMask, char* word) {
    for (int i = 0; word[i]; i++) {
        int in = word[i] - 'a';
        if (!(allowedMask & (1 << in))) {
            return false;
        }
    }
    return true;
}

int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    unsigned int allowedMask = 0;
    int count = 0;

    for (int i = 0; allowed[i]; i++) {
        allowedMask |= (1 << (allowed[i] - 'a'));
    }

    for (int i = 0; i < wordsSize; i++) {
        if (isConsistent(allowedMask, words[i])) {
            count++;
        }
    }

    return count;
}
