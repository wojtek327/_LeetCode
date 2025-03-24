bool ransomeNoteInMagazine(const char magazine, char *ransomNote) {
    while(*ransomNote){
        if(*ransomNote == magazine) {
            *ransomNote = 1;
            return true;
        }
        ransomNote++;
    }
    return false;
}

bool canConstruct(char* ransomNote, char* magazine) {
    if (ransomNote == NULL || magazine == NULL ) { return false; }
    if (*ransomNote == '\0' || *magazine == '\0') { return false; }

    int count = 0;
    int ransomeNoteSize = strlen(ransomNote);

    while(*magazine) {
        if(ransomeNoteInMagazine(*magazine, ransomNote)) {
            *magazine = 0;
            count++;
        }

        if(count == ransomeNoteSize) {
            return true;
        }

        magazine++;
    }

    if(count == ransomeNoteSize) {
        return true;
    }

    return false;
}