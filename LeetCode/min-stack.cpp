// https://leetcode.com/problems/min-stack/
class MinStack
{
    vector<int> container;
    vector<int> min;
    int last_min = INT_MAX;

public:
    /** initialize your data structure here. */
    // MinStack() {
    // }

    void push(int x)
    {
        int lastmin = min.empty() ? ~(1 << 31) : min.back();
        if (lastmin < x)
            min.push_back(lastmin);
        else
            min.push_back(x);

        container.push_back(x);
    }

    void pop()
    {
        container.pop_back();
        min.pop_back();
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