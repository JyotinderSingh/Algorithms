#include<bits/stdc++.h>
using namespace std;

int even_ones(unsigned x)
{
    x ^= x>>16;
    x ^= x>>8;
    x ^= x>>4;
    x ^= x>>2;
    x ^= x>>1;

    return !(x & 1);
}

int main() {
    set<int> s;
    int T, n, x, even = 0, odd = 0;
    cin >> T;
    while (T--) {
        cin>>n;
        s.clear();
        while (n--) {
            cin>>x;
            set <int>::iterator itr;
            for(itr = s.begin(); itr != s.end(); ++itr) {
                if(*itr != x) {
                    s.insert(*itr^x);                    
                }                
            }
            s.insert(x);
        for(itr = s.begin(); itr != s.end(); ++itr) {
            if(even_ones(*itr)) {
                even++;
            }
            else {
                odd++;
            }
        }
        
        // cout<<"\nSET:  ";
        // for(itr = s.begin(); itr != s.end(); ++itr) {
            
        //     cout<<*itr<<" ";
        // }
        // cout<<"\n";

        cout<<even<<" "<<odd<<endl;
        even = 0;
        odd = 0;
        }
        even = 0;
        odd = 0;
    }
}