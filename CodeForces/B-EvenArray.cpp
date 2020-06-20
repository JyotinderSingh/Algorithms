#include <bits/stdc++.h>
using namespace std;

/*
* We split all the positions in which the parity of the index does not match 
* with the parity of the element into two arrays. If there is an odd number 
* in the even index, add this index to the 𝑒 array. Otherwise, if there is an 
* even number in the odd index, add this index to the 𝑜 array. Note that if the
* sizes of the 𝑜 and 𝑒 arrays are not equal, then there is no answer. Otherwise, 
* the array 𝑎 can be made good by doing exactly |𝑜| operations by simply swapping 
* all the elements in the 𝑜 and 𝑒 arrays.
*/
void solve()
{
    int n;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % 2 != i % 2)
        {
            if (i % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
    }
    if (even != odd)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << even << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}