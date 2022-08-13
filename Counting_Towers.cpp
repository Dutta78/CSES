#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main()
{
    int tc;
    cin >> tc;
    /*vector<int>ar(1e6+1,-1);
    ar[1] = 2;
    ar[2] = 8;*/
    vector<int> with_line(1e6, 0);
    vector<int> out_line(1e6 + 1, 0);
    with_line[1] = 1;
    out_line[1] = 1;
    int low = 2;
    while (tc--)
    {
        int n;
        cin >> n;
        if (n < low)
        {
            cout << (with_line[n] + out_line[n]) % mod << endl;
            continue;
        }
        for (; low <= n; low++)
        {
            long long int with_var = (with_line[low - 1]);
            with_var *= 4;
            with_var += out_line[low - 1];

            long long int out_var = out_line[low - 1];
            out_var *= 2;
            out_var += with_line[low - 1];
            with_line[low] = (with_var) % mod;
            out_line[low] = (out_var) % mod;
        }
        cout << (with_line[n] + out_line[n]) % mod << endl;
    }
    // cout << with_line[2] << " " << out_line[2] << endl;
    return 0;
}