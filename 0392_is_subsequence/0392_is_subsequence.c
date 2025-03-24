bool isSubsequence(char* s, char* t) {
    uint8_t i = 0;
    uint16_t j = 0;

    uint8_t len_s = strlen(s);
    uint16_t len_t = strlen(t);
    
    while(i < len_s && j < len_t) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }
    
    return (bool)(i == len_s);
}