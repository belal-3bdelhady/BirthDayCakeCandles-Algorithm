# Birthday Cake Candles Algorithm ( Non-Recursive Design )

---
## Design Technique: Brute force
It sequentially access the whole array to search and count the highest candle height value

---

## Psuodocode
```
Algorithm BirthDayCakeCandles_NonRecusive(candles, n) { // candles is an array
1. tallest <- candles[0] // first number on the array
2. count <- 1 // number of candle found with highest value
3. for i <- 1 to n do {
4.      candle <- candles[i]
5.      if candle > tallest { 
6.          tallest <- candle // new tallest is the candle > tallest
7.          count <- 1 // it will begin from 1 again to count new highest
        }
8.      else if candle = tallest {
9.          count <- count + 1
        }
   } 
10. return count
}
```
---

## Analysis
**Basic Operation:** candle <- candles[index] , assign the candle value from the index to compare and count OR comparison candle > tallest , to check if that candle is taller than tallest one or not

**Time Function of the Algorithm:** f(n) = 5n+3

**Big-Oh** O(n)

**Big-Theta** O(n)

**Big-Omega** O(1)
