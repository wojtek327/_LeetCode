char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int carry = 0;

    int lenc = lenb;
    if(lena > lenb) { lenc = lena; }

    char * c = malloc(lenc+2);

    c[lenc+1] = '\0';

    while(lena || lenb) {
        if(lena) {
            carry += (a[--lena] - 0x30);
        }
        if(lenb) {
            carry += (b[--lenb] - 0x30);
        }
        c[lenc--] = (carry & 1) + 0x30;
        carry >>= 1;
    }

    c[0] = carry + '0';
    return c+(carry^1);
}
