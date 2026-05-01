# Birthday Cake Candles Algorithm ( Non-Recursive Design )

---

## Psuodocode
```
Algorithm BirthDayCakeCandles_NonRecusive(candles[], n) {
1. tallest = candles[0] // first number on the array
2. count = 1 // number of candle found with heighst value
3. from index 1 to n
4.      candle = candles[index]
5.      if candle > tallest 
6.          tallest = candle // new tallest is the candle > tallest
7.          count = 1 // it will begin from 1 again to count new heighst
8.      else if candle == tallest
9.          count++ 
10. return count;
```
---

## Analysis
**Basic Operation:** Comparison of candle > tallest , that check if there is new maximum candle

**Function of the Algorithm:** f(n) = 5n+3

**Big-Oh** O(n)

**Big-Theta** O(n)

**Big-Omega** O(1)