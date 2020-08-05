#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    int CAPACITY = 5;
    vector<int> heap;
    int size;

public:
    MinHeap()
    {
        heap = vector<int>(CAPACITY);
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int peek()
    {
        if (isEmpty())
        {
            throw "Heap is Empty";
        }
        return heap[0];
    }

    int remove()
    {
        if (isEmpty())
        {
            throw "Heap is Empty";
        }
        /*
            * Grab the minimum item. It is at index 0.
            * Move the last itemnin the heap to the top of the heap
            * at index 0
            * Reduce the size of the heap.
            */
        int min_item = heap[0];
        heap[0] = heap[size - 1];
        size--;

        /*
           * Restore the heap since it is very likely messed up now -
           * by bubbling down the element we want swapped up to index 0. 
           */
        heapifyDown();
        return min_item;
    }

    void add(int itemToAdd)
    {
        ensureExtraCapacity();

        /*
            * Place the item at the bottom, far right, of the
            * conceptual binary heap structure
            * Increment size
            */
        heap[size] = itemToAdd;
        size++;

        /*
           * Restore the heap since it is very likely messed up now - 
           * by bubbling up the element we just put in the last empty
           * position of the conceptual binary tree.
           */
        siftUp();
    }

private:
    /************************************
               HEAP RESTORATION HELPERS
        ************************************/

    void heapifyDown()
    {
        /*
           * We will bubble down the item we just swaped to the "top" of the heap
           * after a removal operation to restore the heap
           */

        int index = 0;

        /*
            * Since a binary heap is a complete binary tree, if we have
            * no left child then we have no right child either.
            * So we continue bubbling down as long as there is a left child
            * 
            * A non existent left child immediately tells us that there is no
            * right child
            */

        while (hasLeftChild(index))
        {
            /*
                * By default assume left child is smaller. If a right child
                * exists, see if it can overtake the left child by being smaller
                */
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index))
            {
                smallerChildIndex = getRightChildIndex(index);
            }

            /*
                * If the item we a re sitting on is < the smaller child then
                * nothing needs to happen, and sifting down is finished.
                * 
                * But of the smaller child is smaller than the node we are
                * holding, we should swap and continue sifting down.
                */

            if (heap[index] < heap[smallerChildIndex])
            {
                break;
            }
            else
            {
                swap(index, smallerChildIndex);
            }

            index = smallerChildIndex;
        }
    }

    // Bubble up the item just inserted at the "end" of the heap
    void siftUp()
    {
        /*
            * We will bubble up the item just inserted into the "bottom"
            * if the heap after an insert operation. It will be at the last
            * index so index = size - 1
            */
        int index = size - 1;

        /*
           * While the item haws a parent and the item beats its parent in
           * smallness, bubble this item up
           */

        while (hasParent(index) && heap[index] < parent(index))
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    /************************************
         Helper to access our array easily, 
         perform rudimentary operations, and
         manipulate capacity
        ************************************/

    void swap(int indexOne, int IndexTwo)
    {
        int temp = heap[indexOne];
        heap[indexOne] = heap[IndexTwo];
        heap[IndexTwo] = temp;
    }

    void ensureExtraCapacity()
    {
        if (size == CAPACITY)
        {
            heap.reserve(CAPACITY * 2);
            CAPACITY *= 2;
        }
    }

    int getLeftChildIndex(int parentIndex)
    {
        return 2 * parentIndex + 1;
    }

    int getRightChildIndex(int parentIndex)
    {
        return 2 * parentIndex + 2;
    }

    int getParentIndex(int childIndex)
    {
        return (childIndex - 1) / 2;
    }

    bool hasLeftChild(int index)
    {
        return getLeftChildIndex(index) < size;
    }

    bool hasRightChild(int index)
    {
        return getRightChildIndex(index) < size;
    }

    bool hasParent(int index)
    {
        return index != 0 && getParentIndex(index) >= 0;
    }

    int leftChild(int index)
    {
        return heap[getLeftChildIndex(index)];
    }

    int rightChild(int index)
    {
        return heap[getRightChildIndex(index)];
    }

    int parent(int index)
    {
        return heap[getParentIndex(index)];
    }
};
