int maxNumberOfBalloons(char* text) {
    /*
        b - [0] - ASCII
        a - [1] - ASCII
        l - [2] - ASCII
        o - [3] - ASCII
        n - [4] - ASCII
    */
    int BallonArray[5] = {0x00};
    int retVal = 0;

    while(*text != NULL) {
      switch (*text) {
            case 'b': BallonArray[0]++; break;
            case 'a': BallonArray[1]++; break;
            case 'l': BallonArray[2]++; break;
            case 'o': BallonArray[3]++; break;
            case 'n': BallonArray[4]++; break;
        }
        text++;
    }

    BallonArray[2] /= 2;
    BallonArray[3] /= 2;
    retVal = BallonArray[0];
    for(int i=1; i<5; i++) {
        if(retVal > BallonArray[i]) {
            retVal = BallonArray[i];
        }
    }

    return retVal;
}

//------------------------------------------------------------

//b a l o n
int maxNumberOfBalloons(char* text) {
    if (text == NULL)  { return 0; }
    if (*text == '\0') { return 0; }

    if(strlen(text) < 7) {
        return 0;
    }

    uint16_t charCount[30] = {0x00};

    while (*text) {
        charCount[(unsigned char)*text - 0x61]++;
        text++;
    }
    charCount['l' - 0x61] /= 2;
    charCount['o' - 0x61] /= 2;

    int minVal = charCount['a' - 0x61];

    if(charCount['b' - 0x61] < minVal) {
        minVal = charCount['b' - 0x61];
    }
    if(charCount['l' - 0x61] < minVal) {
        minVal = charCount['l' - 0x61];
    }
    if(charCount['o' - 0x61] < minVal) {
        minVal = charCount['o' - 0x61];
    }
    if(charCount['n' - 0x61] < minVal) {
        minVal = charCount['n' - 0x61];
    }

    return minVal;
}
