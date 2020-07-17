// https://leetcode.com/problems/remove-k-digits/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> ans;
        for (char i : num)
        {

            /*
            * pop an element if current element being scanned is
            * smaller than the one already in stack
            * i.e. the element that came before the current one was 
            * larger, hence should've been removed
            */
            while (!ans.empty() && i < ans.top() && k)
            {
                ans.pop();
                k--;
            }

            /*
            * Push the element into the stack only if either
            * 1. The number isn't 0
            * 2. Number if 0, but stack isn't empty. i.e. it
            * won't be a trailing 0
            */
            if (!ans.empty() || i != '0')
            {
                ans.push(i);
            }
        }

        /*
        * If k > 0 and there's still elements left in the
        * stack, pop them (means all the last few elements were
        * greater than the ones before them)
        */
        while (k-- && !ans.empty())
        {
            ans.pop();
        }

        // simply return if stack is empty
        if (ans.empty())
        {
            return "0";
        }

        // we store the output in num itself to avoid extra space
        int n = ans.size();
        while (!ans.empty())
        {
            num[ans.size() - 1] = ans.top();
            ans.pop();
        }

        return num.substr(0, n);
    }
};

//////// ITERATIVE SCAN SOLUTION /////////

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.size())
        {
            return "0";
        }
        reverse(num.begin(), num.end());

        int i = num.size() - 1;

        while (i > 0 && k != 0)
        {
            if (num[i] > num[i - 1])
            {
                num.erase(num.begin() + i);
                k--;
                if (i < num.size() - 1)
                {
                    i++;
                }
            }
            else
            {
                i--;
            }
        }

        while (k > 0)
        {
            num.erase(num.begin());
            k--;
        }

        while (num.back() == '0' && num.size() > 1)
        {
            num.erase(num.size() - 1);
        }

        reverse(num.begin(), num.end());
        return num;
    }
};