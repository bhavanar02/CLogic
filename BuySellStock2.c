#include <stdio.h>

int maxProfit(int* prices, int pricesSize) 
{
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) 
    {
        if (prices[i] > prices[i - 1]) 
        {
            maxProfit += (prices[i] - prices[i - 1]);
        }
    }

    return maxProfit;
}

int main() 
{
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int prices2[] = {1, 2, 3, 4, 5};
    int prices3[] = {7, 6, 4, 3, 1};

    printf("%d\n", maxProfit(prices1, sizeof(prices1) / sizeof(prices1[0])));
    printf("%d\n", maxProfit(prices2, sizeof(prices2) / sizeof(prices2[0])));
    printf("%d\n", maxProfit(prices3, sizeof(prices3) / sizeof(prices3[0])));

    return 0;
}
