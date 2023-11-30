int maxProfit(int* prices, int pricesSize)
{
    int profit = 0;
    int min = prices[0];
    for(int i=1; i<pricesSize; i++)
    {
        if(prices[i] < min) 
            min = prices[i];
            int temp = prices[i] - min;
        if(temp > profit) 
            profit = temp;
    }
    return profit;
}