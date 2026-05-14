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

    int total_candles = 0;

    printf("Enter the number of candles: ");
    scanf("%d", &total_candles);
 
    int candles[total_candles];

    if (total_candles<=0){
        printf("Please input a positive number \n");
        return 1 ;
    }
    
    printf("Enter the heights of the candles: \n");
    for (int i = 0; i < total_candles; i++) {
        scanf("%d", &candles[i]);
    }

    for (int i = 0; i < total_candles; i++) {
        if (candles[i] <= 0){
            printf("Candle hight must be positive \n");
            return 1 ;
        }
    }
    
    int count = numOfHighestCandles(candles, total_candles);
    printf("Number of highest candles: %d\n", count);

    return 0;
}