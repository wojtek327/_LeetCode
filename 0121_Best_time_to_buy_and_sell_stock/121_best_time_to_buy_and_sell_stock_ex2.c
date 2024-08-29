int maxProfit(int* prices, int pricesSize) {
    int low_price = INT_MAX;
    int high_price = 0;
    int profit = 0;
    for(int i=0; i<pricesSize; i++)
    {
        if(prices[i] < low_price)
        {
            low_price = prices[i];
        }

        profit = prices[i] - low_price;

        if(profit > high_price) {
            high_price = profit;
        }
    }

    return (high_price);
}
