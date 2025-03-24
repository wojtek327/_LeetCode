/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

int value(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

int romanToInt(char* s) {
    int intRet = 0;
    int n = strlen(s);
    int i = 0;

    while (i < n){
        if((i < n - 1) && (value(s[i])<value(s[i+1]))) {
            intRet += value(s[i+1]) - value(s[i]);
            i+=2;
        } else {
            intRet += value(s[i]);
            i+=1;
        }
    }

    return intRet;
}