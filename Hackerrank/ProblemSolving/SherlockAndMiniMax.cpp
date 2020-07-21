#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sherlockAndMinimax function below.
int sherlockAndMinimax(vector<int> arr, int p, int q)
{
    int result = INT_MIN, num = INT_MIN, cur;
    sort(arr.begin(), arr.end());
    if (arr[0] > q)
    {
        return p;
    }
    else if (arr[arr.size() - 1] < p)
    {
        return q;
    }
    else
    {
        if (arr[0] > p)
        {
            if (result < arr[0] - p)
            {
                result = arr[0] - p;
                num = p;
            }
        }

        if (arr[arr.size() - 1] < q)
        {
            if (result < q - arr[arr.size() - 1])
            {
                result = q - arr[arr.size() - 1];
                num = q;
            }
        }

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            cur = (arr[i] + arr[i + 1]) / 2; //ideal value of M for the max possible distance
            if (cur >= p && cur <= q && (cur - arr[i]) > result)
            {
                result = cur - arr[i];
                num = cur;
            }
            else if (cur > q)
            {
                if (q - arr[i] > result)
                {
                    result = q - arr[i];
                    num = q;
                }
            }
            else if (cur < p)
            {
                if (arr[i + 1] - p > result)
                {
                    result = arr[i + 1] - p;
                    num = p;
                }
            }
        }
    }

    return num;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string pq_temp;
    getline(cin, pq_temp);

    vector<string> pq = split_string(pq_temp);

    int p = stoi(pq[0]);

    int q = stoi(pq[1]);

    int result = sherlockAndMinimax(arr, p, q);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
