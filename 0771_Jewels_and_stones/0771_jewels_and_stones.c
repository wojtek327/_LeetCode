bool IfStonesIsInJewel(const char stone, const char *jewel) {
    while(*jewel){
        if(*jewel == stone) {
            return true;
        }
        jewel++;
    }
    return false;
}

int numJewelsInStones(char* jewels, char* stones) {
    if (jewels == NULL || stones == NULL ) { return false; }
    if (*jewels == '\0' || stones == '\0') { return false; }

   uint8_t count = 0;

    while(*stones) {
        if(IfStonesIsInJewel(*stones, jewels)) {
            count++;
        }
        stones++;
    }

    return count;
}
