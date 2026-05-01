
# Birthday Cake Candles Algorithm ( Recursive Design )

----------------------------------------------------------------------------------------------------------------------------

## Design Technique : Decrease and Conquer
   Decrease and Conquer is applied by reducing the problem size (total_candles) by a constant value of 1 in each recursive call.
   The algorithm solves this single smaller subproblem and extends the result to find the tallest birthday cake candles by evaluating the current element against the maximum and count the number of reccurrances.

----------------------------------------------------------------------------------------------------------------------------

## Pseudocode 

1. algorithm numOfHighestCandles( candles , total_candles ) //candles is an array of integers 
2. {   
3.     // Base Case
4.     max <- 0
5.     count <- 0
6. 
7.     if total_candles = 0 
8.         return 0
9. 
10.     // max and count in one recursion
11.     numOfHighestCandles( candles , total_candles - 1 )
12. 
13.     if candles[total_candles - 1] > max
14.         max  candles[total_candles - 1]
15.         count <- 1
16.     else if candles[total_candles - 1] = max
17.         count <- count + 1
18. 
19.     return count
20. } 

----------------------------------------------------------------------------------------------------------------------------

## Analysis 

**input’s size**
total_candles

**Basic Operation**
comparison > in line 11. candles[total_candles - 1] > max

**Check whether the number of times the basic operation is executed may vary due to the inputs type**
No , Best case = Worst case 
O(total_canles) = Ω(total_candles) = θ(total_candles)

**Solution method**
Iteration Approach

**Consider the recurrence**
T(total_candles) = T(total_candles-1) + 1 , and   T(0) = θ(0).

**Expanding the above terms**
T(total_candles) = T(total_candles-1) +1                                   , T(total_candles-1) = T(total_candles-2) + 1
thus,
T(total_candles) = (T(total_candles-2)+1) +1 =T(total_candles-2) + 2       , T(total_candles-2) = T(total_candles-3) + 1
thus,
T(total_candles) = (T(total_candles-3) +1) + 2 = T(total_candles-3) + 3    , T(total_candles-3) = T(total_candles-4) + 1
thus,
T(total_candles) = T(total_candles-4) +4 

**General Form**
T(total_candles) = T(total_candles-k) + k

**Time Complexity**
T(total_candles-k)= T(0) = 0 , when k = total_candles
Thus  ,	T(total_candles) = 0 + (total_candles) = θ(total_candles)
Hence ,	T(total_candles) = θ(total_candles)
