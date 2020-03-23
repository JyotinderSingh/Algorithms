#include <bits/stdc++.h>
using namespace std;

const int kNumTelDigits = 10;
const array<string, kNumTelDigits> kMapping = {"0", "1", "ABC", "DEF", "GHI", "JKL"
                                                                              "MNO",
                                               "PQRS", "TUV", "WXYZ"};

void PhoneMnemonicHelper(const string &phone_number, int digit, string *partial_mnemonic, vector<string> *mnemonics);

vector<string> PhoneMnemonic(const string &phone_number)
{
    // define a string as long as the phone number and initialize it with an empty value
    // 0 is the ascii value we are using
    string partial_mnemonic(phone_number.size(), 0);
    cout<<partial_mnemonic[0]<<endl;
    vector<string> mnemonics;
    PhoneMnemonicHelper(phone_number, 0, &partial_mnemonic, &mnemonics);
    return mnemonics;
}

void PhoneMnemonicHelper(const string &phone_number, int digit, string *partial_mnemonic, vector<string> *mnemonics)
{
    if (digit == phone_number.length())
    {
        // All digits have been processed, so add partial_mnemonic to mnemonics
        // We add a copy since subsequent calls modify partial_mnemonic
        mnemonics->push_back(*partial_mnemonic);
    }
    else
    {
        // Try all possible characters for this digit
        for (char c : kMapping[phone_number[digit] - '0'])
        {
            (*partial_mnemonic)[digit] = c;
            PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
        }
    }
}

// tester code
int main()
{
    for (auto str : PhoneMnemonic("234"))
    {
        cout << str << endl;
    }
}