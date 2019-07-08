#!/bin/python3
import os

# Complete the maxMin function below.
def maxMin(k, arr):
    arr.sort()
    # print(arr)
    diffs = [0] * (len(arr) - k)
    for i in range(0, len(arr) - k):
        diffs[i] = abs(arr[i] - arr[i+k-1])
    # print(diffs)
    return min(diffs)

if __name__ == '__main__':
    
    n = int(input())

    k = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    print(maxMin(k, arr))
