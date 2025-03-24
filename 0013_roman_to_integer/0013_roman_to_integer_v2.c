int romanToInt(char * s){
    char array[7] = {'I','V','X','L','C','D','M'};
    int output[7] = {1, 5, 10, 50, 100, 500, 1000};
    int sum = 0;

    if(*s == NULL) { return 0; }

    while(*s)
    {
        int val1 = 0;
        int val2 = 0;

        for(uint8_t i=0;i<7;i++) {
            if(array[i] == *s) {
                val1 = output[i];
            }
            if(array[i] == *(s+1)) {
                val2 = output[i];
            }

            if(val1 != 0 && val2 != 0) {
                i = 7;
            }
        }

        if(*(s+1) != NULL)
        {
            if (val1 >= val2) { sum = sum + val1; }
            else {
                sum = sum + val2 - val1;
                *s++;
            }
        }
        else
        {
            sum = sum + val1;
        }

        *s++;
    }
    return sum;
}
