int fib(int n){
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    for(uint8_t i = 0; i<n; i++)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return t1;
}
