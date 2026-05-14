#include <stdio.h>

void merge(int arr[], int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[first + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2)
    {
        if (Left[i] >= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        arr[k++] = Left[i++];
    while (j < n2)
        arr[k++] = Right[j++];
}

void mergeSort(int arr[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int numOfHighestCandles(int candles[], int total_candles) {
    if (total_candles <= 0)
        return 0;

    mergeSort(candles, 0, total_candles - 1);

    int max = candles[0];
    int count = 0;
    for (int i = 0; i < total_candles; i++) {
        if (candles[i] == max) {
            count++;
        } else {
            break; 
        }
    }
    return count;
}

int main() {

    int total_candles = 0;

    printf("Enter the number of candles: ");
    scanf("%d", &total_candles);
 
    if (total_candles<=0){
        printf("Please input a positive number \n");
        return 1 ;
    }

    int candles[total_candles];

    
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