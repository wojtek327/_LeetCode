int myAtoi(char *s) {
    if (s == NULL) { return 0; }

    long long int output = 0;
    int sign = 1;

    // Ignore leading whitespace
    while (*s == ' ') {
        s++;
    }

    // Sign check
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        output = output * 10 + (*s - '0');

        // Check for overflow
        if (sign == 1 && output > INT_MAX) {
            return INT_MAX;
        } else if (sign == -1 && -output < INT_MIN) {
            return INT_MIN;
        }

        s++;
    }

    return (int)(output * sign);
}

//Simple myAtoi
//Konwersja bezpośrednia, należy przekazać do funkcji odpowieni string
//bez znaków innych niż cyfry
int myAtoi(char* str)
{
    // Initialize result
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        res = res * 10 + str[i] - '0';
    }

    return res;
}
