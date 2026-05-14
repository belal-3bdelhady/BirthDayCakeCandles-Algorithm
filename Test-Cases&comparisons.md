# BirthDayCakeCandles-Algorithm :

    the cake for a child's birthday. You have decided the cake will have
one candle for each year of their total age. They will only be able to blow out the tallest
of the candles.The Algorithm count how many candles are tallest. 

***************************************************************************************************************************************************

# Test Cases :

### Test Case 1: Random ###

**Input**:

4
3 2 1 3
Expected Output: 2

### Test Case 2: Identical Elements ###

**Input**:

5
4 4 4 4 4
Expected Output: 5


### Test Case 3: Minimum Input Size ###

**Input**:

1
15
Expected Output: 1

### Test Case 4: Large Values ###

Input:

8
9999 4 9999 5 9999 3 1 9999
Expected Output: 4

### Test Case 5: Input Validation Handling (Negative Heights) ###

Input:

3
5 -2 5 2
Expected Behavior & Output: Candle hight must be positive

### Test Case 6: Number of candles <= 0 ###

Input:

0
5 -2 5 2
Expected Behavior & Output: Please input a positive number

***************************************************************************************************************************************************

# Comparison :

=========================================
PERFORMANCE COMPARISON  (time in s)
n         Iterative      Recursive    Recursive with sorting
4         0.009s         0.001s       .012s
20        0.010s         0.003s       .008s
100       0.016s         0.004s       .016s
1000      0.016s         0.011s       .012s
100000    0.053s         0.053s       .070s
1000000   0.410s         0.402s       .576s
5000000                              2.103s

=========================================
=========================================
ALGORITHM SUMMARY
Feature               Iterative         Recursive             Recursive with sorting
Design techniqe       Brute force       Decrease & conquer    divide and conquer
Time Complexity       0(n)              0(n)                  0(n log n)
Stack Overflow Risk   None              Yes (large n)         Yes (large n)
Best for              General use       Learning recursion    Learning recursion
Space Complexity      0(n)              0(n)                  0(n) 

*************************************************************************************************************************************************
# Testing Script
time (python3 -c "import random; print(1000); print(' '.join(str(random.randint(1, 1000)) for _ in range(1000)))" | ./Recursive/implementation)

time (python3 -c "import random; print(1000); print(' '.join(str(random.randint(1, 1000)) for _ in range(1000)))" | ./Recursive-with-sorting/implementation2)

time (python3 -c "import random; print(1000); print(' '.join(str(random.randint(1, 1000)) for _ in range(1000)))" | ./Non-Recursive/Non-Recursive)
