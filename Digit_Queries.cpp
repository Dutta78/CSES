#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow10(int x)
{
    ll res = 1;
    for (int i = 0; i < x; i++)
        res *= 10;
    return res;
}

int solve(ll k)
{
    if (k < 9)
        return int(k + 1);
    int len = 1;
    while (9 * pow10(len - 1) * len < k)
    {
        k -= (9 * pow10(len - 1) * len);
        len++;
    }
    string s = to_string(pow10(len - 1) + k / len);

    return (s[k % len]) - '0';
}
int main()
{
    int queries;
    cin >> queries;
    while (queries--)
    {
        ll k;
        cin >> k;
        cout << solve(k - 1) << "\n";
    }
    return 0;
}