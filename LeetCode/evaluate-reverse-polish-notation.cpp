// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto token : tokens)
        {
            if (token == "+" || token == "-" || token == "/" || token == "*")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                switch (token.front())
                {
                case '+':
                    st.push(y + x);
                    break;
                case '-':
                    st.push(y - x);
                    break;
                case '*':
                    st.push(y * x);
                    break;
                case '/':
                    st.push(y / x);
                    break;
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};