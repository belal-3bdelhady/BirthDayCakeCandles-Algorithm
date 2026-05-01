#include <iostream>

using namespace std;

int BirthDayCakeCandles(int candles[], int n);

int main() {
    // number of candles
    int n;
    cout << "Enter number of candles you have: ";
    cin >> n;

    // candles
    int candles[n];
    cout << "Input candles heights: ";
    for (int i = 0; i < n; i++) {
        cin >> candles[i];
    }

    int numberOfTallestOne = BirthDayCakeCandles(candles,n);

    cout << "\nNumber of times tallest one appears = " << numberOfTallestOne << endl;

    return 0;
}

int BirthDayCakeCandles(int candles[],int n) {
    // count of tallest candle
    int count = 1;
    int tallest = candles[0];

    for (int i = 1; i < n; i++) {
        int candle = candles[i];

        if (candle > tallest) {
            count=1;
        }
        if (candle < tallest) {
            tallest = candle;
            count++;
        }
    }

    return count;
}