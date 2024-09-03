//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//n = 2 => 2 (1+1)(2)
//n = 3 => 3 (1 + 1 + 1) (1 + 2) (2 + 1)
//n = 4 => 5 (1 + 1 + 1 + 1) (2 + 1 + 1) (1 + 1 + 2) (2 + 2) (1 + 2 + 1)
//n = 5 => 8
//n = 6 => 13
//n = 7 => 21
//n = 8 => 34
//n = 9 => 55
//n = 10 => 89
//n = 11 => 144
//n = 12 => 233
//n = 13 => 377
//n = 14 => 610
//n = 15 =>
//n <= 1 <= 45
//Fibonacci

int climbStairs(int n) {
    if(n > 45) { return -1; }

    uint32_t a = 0;
    uint32_t b = 1;

    for(uint8_t i=0;i<n;i++)
    {
        b += a;
        a = b-a;
    }

    return b;
}
