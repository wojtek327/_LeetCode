int hammingWeight(uint32_t n) {
    if(n == 0) { return 0; }

    int numberOfOnes = 0;

    while(n)
    {
        if(n & 1 == 1) { numberOfOnes++; }
        n >>= 1;
    }

    return numberOfOnes;
}
