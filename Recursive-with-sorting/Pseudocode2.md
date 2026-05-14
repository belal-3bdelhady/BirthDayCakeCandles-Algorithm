# Birthday Cake Candles Algorithm ( Recursive Design )

----------------------------------------------------------------------------------------------------------------------------

## Design Technique : Divide and Conquer
Divide: The array is recursively split into two halves until reaching the base case (a single element).
Conquer: Since a single element is inherently sorted, the smallest sub-problems are solved automatically.
Combine: The merge function is used to reintegrate the halves in descending order, allowing us to find the maximum value at the first index and count its frequency efficiently.

----------------------------------------------------------------------------------------------------------------------------

## Pseudocode:
```
1.  algorithm Merge(arr, first, mid, last)
2.  {
3.      // Calculate sizes of two subarrays to be merged
4.      n1 <- mid - first + 1
5.      n2 <- last - mid
6.  
7.      // Create temporary arrays
8.      Create arrays Left[n1] and Right[n2]
9.  
10.     // Copy data to temporary arrays
11.     for i <- 0 to n1 - 1
12.         Left[i] <- arr[first + i]
13.     for j <- 0 to n2 - 1
14.         Right[j] <- arr[mid + 1 + j]
15. 
16.     // Initial indexes of first, second and merged subarrays
17.     i <- 0
18.     j <- 0
19.     k <- first
20. 
21.     // Merge the temporary arrays back into arr[first..last]
22.     while i < n1 and j < n2
23.     {
24.         if Left[i] >= Right[j]
25.         {
26.             arr[k] <- Left[i]
27.             i <- i + 1
28.         }
29.         else
30.         {
31.             arr[k] <- Right[j]
32.             j <- j + 1
33.         }
34.         k <- k + 1
35.     }
36. 
37.     // Copy remaining elements of Left[], if any
38.     while i < n1
39.     {
40.         arr[k] <- Left[i]
41.         i <- i + 1
42.         k <- k + 1
43.     }
44. 
45.     // Copy remaining elements of Right[], if any
46.     while j < n2
47.     {
48.         arr[k] <- Right[j]
49.         j <- j + 1
50.         k <- k + 1
51.     }
52. }
```



## DIVIDE & CONQUER ##
```
1. ALGORITHM Mergesort(A, p, r)
2.     IF p < r                                    
3.     THEN q = FLOOR[(p + r)/2]        
4.          MERGE_Sort (A, p, q)                  T(n/2)
5.          MERGE_Sort (A, q + 1, r)              T(n/2) 
6.          MERGE (A, p, q, r)
```



```
1.  algorithm numOfHighestCandles(candles, total_candles)
2.  {
3.      if total_candles <= 0
4.          return 0
5.  
6.      MergeSort(candles, 0, total_candles - 1)
7.  
8.      max <- candles[0]
9.      count <- 0
10. 
11.     for i <- 0 to total_candles - 1
12.     {
13.         if candles[i] = max
14.             count <- count + 1
15.         else
16.             break
17.     }
18. 
19.     return count
20. }
```


-------------------------------------------------------------------------------------------------------------------------------------------------
## Analysis of merge algorithm

**input’s size**
n = array size = last - first + 1 

**Check whether the number of times the basic operation is executed may vary due to the inputs type**
Yes, the number of comparisons varies depending on the input values.
Best case: min(n1, n2) comparisons (occurs when all elements of one subarray are merged before any element of the second subarray).
Worst case: n1 + n2 - 1 comparisons = n - 1 comparisons (occurs when pointers i and j alternate until the very last element).
Overall time complexity: θ(n) in all cases because the total array writes always equal exactly n regardless of comparison counts.

**Basic Operation**
comparison >= in line 24 while loop: Left[i] >= Right[j]

**Set up sum expressing the # of times basic operation is executed**
        n−1
 C(n) = ∑   1 = (n-1)-1+1 = n-1
        k=1​

**Find closed form for the sum or at least establish its order of growth**
C(n)∈Θ(n)

---------------------------------------------------------------------------------------------------------------------------------------------------

## Analysis of mergeSort algorithm

**input’s size**
n = last - first + 1 (the total number of elements in the array to be sorted)

**Basic Operation**
comparison >= executed inside the merge() function: Left[i] >= Right[j]

**Check whether the number of times the basic operation is executed may vary due to the inputs type**
No, the asymptotic growth rate does not vary. The algorithm always splits the array into halves and merges them regardless of the initial order.

**Solution method**
Iteration method

**Consider the recurrence**
T(n) = 2T(n/2) + cn , for n > 1, and T(1) = θ(1).
(where cn represents the linear time θ(n) required by the merge function to combine the divided halves)

**Expanding the above terms**
T(n) = 2T(n/2) + cn                                   , T(n/2) = 2T(n/4) + c(n/2)
thus,
T(n) = 2(2T(n/4) + cn/2) + cn = 4T(n/4) + 2cn         , T(n/4) = 2T(n/8) + c(n/4)
thus,
T(n) = 4(2T(n/8) + cn/4) + 2cn = 8T(n/8) + 3cn

**General Form**
T(n) = (2^k) * T(n/(2^k)) + kcn

**Time Complexity**
The base case is reached when n/(2^k) = 1
Thus, n = 2^k
Taking log base 2 on both sides: k = log2(n)

Substituting k back into the General Form:

T(n) = (2^(log (n))) * T(1) + cn x log2(n)
              2

T(n) = n * θ(1) + cn * log2(n)
T(n) = θ(n) + θ(n log n)
Hence, T(n) = θ(n log n) = O(total_canles) = Ω(total_candles)

---------------------------------------------------------------------------------------------------------------------------------------------------
## Analysis of numOfHighestCandles algorithm

**input’s size**
total_candles (let's call it n where n = total_candles)

**Basic Operation**
comparison Left[i] >= Right[j] inside the mergeSort step (since it asymptotically dominates the execution time), and comparison candles[i] == max inside the counting loop.

**Check whether the number of times the basic operation is executed may vary due to the inputs type**
No , the input type is fixed .
Best case = Worst case = Average case
O(n log n) = Ω(n log n) = θ(n log n)

**Solution method**
Iteration Method

**Consider the total execution time**
T(n) = T_mergeSort(n) + T_count(n) + θ(1)

T_mergeSort(n) = θ(n log n)

T_count(n) = c x k , where k is the number of loop iterations before breaking (1 <= k <= n).

**Expanding the above terms**
T(n) = θ(n log n) + c*k + θ(1)
T(n) = θ(n log n) + O(n)

**General Form**
T(n) = θ(n log n) + O(n)

**Time Complexity**
Thus, T(n) = θ(n log n) + θ(n)
Hence, T(n) = θ(n log n)