int mySqrt(int x)
{
    unsigned long i=1;

    while(i*i<=x)
    {
        i++;
    }

    return i-1;
}
