int scoreOfString(char* s) {
    int stringLen = strlen(s);
    int value = 0;

    for(int i = 1; i<stringLen; i++) {
        value += abs((uint8_t)s[i-1] - (uint8_t)s[i]);
    }

    return value;
}


//----------------------------------------------------------

int abs_test(int v)
{
  return v * ((v>0) - (v<0));
}

int scoreOfString(char* s) {
    int stringLen = strlen(s);
    int value = 0;

    for(int i = 1; i<stringLen; i++) {
        value += abs_test((int)s[i-1] - (int)s[i]);
    }

    return value;
}
