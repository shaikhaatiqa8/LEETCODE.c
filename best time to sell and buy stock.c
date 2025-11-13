#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int i = 0; i < pricesSize; i++) {
        // Update the minimum price seen so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Calculate profit if we sell at current price
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}

// Alternative solution (more intuitive)
int maxProfitAlternative(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        // Update max profit if selling at current price gives better profit
        if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
        // Update min price if current price is lower
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
    }
    
    return maxProfit;
}

int main() {
    // Test case 1: Example from problem
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = 6;
    printf("Prices: [7,1,5,3,6,4]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices1, size1));
    
    // Test case 2: Decreasing prices (no profit possible)
    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = 5;
    printf("Prices: [7,6,4,3,1]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices2, size2));
    
    // Test case 3: Single day (no transaction possible)
    int prices3[] = {5};
    int size3 = 1;
    printf("Prices: [5]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices3, size3));
    
    // Test case 4: Two days with profit
    int prices4[] = {3, 8};
    int size4 = 2;
    printf("Prices: [3,8]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices4, size4));
    
    // Test case 5: Two days without profit
    int prices5[] = {8, 3};
    int size5 = 2;
    printf("Prices: [8,3]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices5, size5));
    
    // Test case 6: Multiple peaks and valleys
    int prices6[] = {3, 8, 1, 5, 9, 2, 10};
    int size6 = 7;
    printf("Prices: [3,8,1,5,9,2,10]\n");
    printf("Max Profit: %d\n\n", maxProfit(prices6, size6));
    
    return 0;
}
