// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue
{
    int front, rear, size;
    const int maxSize;
    vector<int> q;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : size(0), maxSize(k), front(0), rear(-1), q(vector<int>(k, 0))
    {
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (size == maxSize)
            return false;
        if (++rear == maxSize)
            rear = 0;
        q[rear] = value;
        ++size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (size == 0)
            return false;
        if (++front == maxSize)
            front = 0;
        --size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        return size == 0 ? -1 : q[front];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        return size == 0 ? -1 : q[rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */