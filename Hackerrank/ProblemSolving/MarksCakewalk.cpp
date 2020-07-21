#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool cmp(int a, int b) {
    return a > b;
}

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end(), cmp);
    long total = 0;
    long mul = 1;
    for (long i = 0; i < calorie.size(); ++i)
    {
        total += mul*calorie[i];
        mul *= 2;
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string calorie_temp_temp;
    getline(cin, calorie_temp_temp);

    vector<string> calorie_temp = split_string(calorie_temp_temp);

    vector<int> calorie(n);

    for (int i = 0; i < n; i++) {
        int calorie_item = stoi(calorie_temp[i]);

        calorie[i] = calorie_item;
    }

    long result = marcsCakewalk(calorie);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
