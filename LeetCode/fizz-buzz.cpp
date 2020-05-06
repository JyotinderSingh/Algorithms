// https://leetcode.com/problems/fizz-buzz/
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res(n);
        for (int i = 1; i <= n; ++i)
        {
            string front = !(i % 3) && !(i % 5) ? "FizzBuzz" : !(i % 3) ? "Fizz" : !(i % 5) ? "Buzz" : to_string(i);
            string rear = !(n % 3) && !(n % 5) ? "FizzBuzz" : !(n % 3) ? "Fizz" : !(n % 5) ? "Buzz" : to_string(n);
            res[i - 1] = front;
            res[--n] = rear;
        }
        return res;
    }
};