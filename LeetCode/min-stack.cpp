class MinStack
{
    vector<int> min, container;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        int lastMin = min.size() ? min.back() : INT_MAX;
        x < lastMin ? min.push_back(x) : min.push_back(lastMin);
        container.push_back(x);
    }

    void pop()
    {
        container.pop_back(), min.pop_back();
    }

    int top()
    {
        return container.back();
    }

    int getMin()
    {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */