#include <stdio.h>

int max = 0;
int count = 0;

int numOfHighestCandles(int candles[], int total_candles) {
    // Base case
    if (total_candles == 0)
        return 0;

    numOfHighestCandles(candles, total_candles - 1);

    // max and count in one recursion
    if (candles[total_candles - 1] > max) {
        max = candles[total_candles - 1];
        count = 1;
    } else if (candles[total_candles - 1] == max) {
        count++;
    }

    return count;
}

int main() {

    int candles[100] ;
    int total_candles = 0;
    printf("Enter the number of candles: ");
    scanf("%d", &total_candles);
    printf("Enter the heights of the candles: \n");
    for (int i = 0; i < total_candles; i++) {
        scanf("%d", &candles[i]);
    }
    int count = numOfHighestCandles(candles, total_candles);
    printf("Number of tallest candles: %d\n", count);

    return 0;
}