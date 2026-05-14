#include <stdio.h>

int BirthDayCakeCandles(int candles[], int n);

int main() {
    // number of candles
    int n;
    printf("Enter number of candles you have: ");
    scanf("%d", &n);

    if (n<=0){
        printf("Please input a positive number \n");
        return 1 ;
    }

    // candles
    int candles[n];
    printf("Input candles heights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &candles[i]);
    }

    for (int i = 0; i < n; i++) {
        if (candles[i] <= 0){
            printf("Candle hight must be positive \n");
            return 1 ;
        }
    }

    int numberOfTallestOne = BirthDayCakeCandles(candles,n);

    printf("\nNumber of times tallest one appears = %d \n", numberOfTallestOne);

    return 0;
}

int BirthDayCakeCandles(int candles[],int n) {
    // count of tallest candle
    int count = 1;
    int tallest = candles[0];

    for (int i = 1; i < n; i++) {
        int candle = candles[i];

        if (candle > tallest) {
            tallest = candle;
            count = 1;
        }
        else if (candle == tallest) {
            count++;
        }
    }

    return count;
}