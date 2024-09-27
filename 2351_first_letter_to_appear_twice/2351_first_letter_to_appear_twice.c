char repeatedCharacter(char* s) {
    char array[26] = {0x00};

    while(*s != '\0') {
        if(array[*s - 0x61] == 1)
        {
            return *s;
        }
        array[*s - 0x61]++;
        s++;
    }
    return '\0';
}
