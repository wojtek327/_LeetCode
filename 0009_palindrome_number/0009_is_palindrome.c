bool isPalindrome(int x) {
    int r = 0;
    uint64_t test = 0;

    if(x < 0){ return false; }
    if((x) > INT_MAX || (x) < INT_MIN)  { return false; }

    int val = x;

    while (val != 0)
    {
        test = r;
        test = (test * 10);

        if((test) > INT_MAX) {
            return false;
        }

        r = test + val%10;
        val = val/10;
    }

    if(x==r) { return true; }
    else { return false; }
}
