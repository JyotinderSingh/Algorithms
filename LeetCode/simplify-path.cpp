// https://leetcode.com/problems/simplify-path/

class Solution
{
public:
    string simplifyPath(string path)
    {
        string res, token;
        stack<string> st;
        stringstream ss(path);
        while (getline(ss, token, '/'))
        {
            if (token == "" || token == ".")
                continue;
            // if the token ".." and the stack is not empty
            if (token == ".." && !st.empty())
                st.pop();
            // if token is a name
            else if (token != "..")
                st.push(token);
        }
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};

///// EPI SOLUTION ////////

class Solution
{
public:
    string simplifyPath(string path)
    {
        string res;
        if (path.empty())
            return res;

        vector<string> path_names; // vector as a stack

        // special case: starts with "/", hence is an absolute path
        if (path.front() == '/')
        {
            path_names.push_back("/");
        }

        stringstream ss(path);
        string token;

        while (getline(ss, token, '/'))
        {
            if (token == "..")
            {
                if (path_names.empty() || path_names.back() == "..")
                {
                    path_names.push_back(token);
                }
                else
                {
                    if (path_names.back() == "/")
                    {
                        // throw invalid_argument("Path error");
                        continue;
                    }
                    path_names.pop_back();
                }
            }
            // if the token is a name
            else if (token != "." && token != "")
            {
                path_names.push_back(token);
            }
        }
        for (auto p : path_names)
            cout << p << " ";
        if (!path_names.empty())
        {
            res = path_names.front();
            for (int i = 1; i < path_names.size(); ++i)
            {
                // Avoid starting "//"
                if (i == 1 && res == "/")
                {
                    res += path_names[i];
                }
                else
                {
                    res += "/" + path_names[i];
                }
            }
        }
        return res.empty() ? "/" : res;
    }
};