// https://www.youtube.com/watch?v=yQ84lk-EXTQ

#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    void sortNearlySortedArray(vector<int> arr, int k)
    {
        // Create a min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();

        /*
        * Add the first k elements to the heap. Guard against the case
        * that there are less than k elements in the whole array.
        */
        for (int i = 0; i < k && k < n; ++i)
        {
            minHeap.push(arr[i]);
        }

        /*
       * ADd and place...add and place...add and place from the heap.
       * Initially, we added iterms from index 0 to index k - 1. We continue
       * reading from index k and begin our minimum element placements 
       * at index 0
       * 
       * Continue while the read index stays within the index 
       * boundes of the array.
       * When it runs over we will have no more items to add to the heap.
       */

        int readIndex = k;
        int placementIndex = 0;

        while (readIndex < n)
        {
            /*
          * Add the next element to be considered in the heap. The heap
          * will hold at max k + 1 items.
          */
            minHeap.push(arr[readIndex]);
            readIndex++;

            /*
         * Read the smallest item to palce into the array. This item will be
         * placed where it belongs by the definition of what k represents.
         */
            arr[placementIndex] = minHeap.top();
            minHeap.pop();
            placementIndex++;
        }

        // Empty out the rest of the heap and do the placements
        while (!minHeap.empty())
        {
            arr[placementIndex++] = minHeap.top();
            minHeap.pop();
        }
    }
};