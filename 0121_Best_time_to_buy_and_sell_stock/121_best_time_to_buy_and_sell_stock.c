static inline int min(int x, int y)
{
    return ((x < y) ? x : y);
}
static inline int max(int x, int y)
{
    return ((x > y) ? x : y);
}

int maxProfit(int* prices, int pricesSize) {
    int low_price = INT_MAX;
    int high_price = 0;

    for(int i=0; i<pricesSize; i++)
    {
        low_price = min(low_price, prices[i]);
        high_price = max(prices[i] - low_price, high_price);
    }

    return (high_price);
}
