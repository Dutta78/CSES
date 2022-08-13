#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long low = 1;
    long long high = 1e18;
    long long ans = 1e18;
    long long l = (n * n + 1) / 2;
    while (low <= high)
    {
        long long avg = low + (high - low) / 2;
        long long cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += min(n, avg / i);
        }
        if (cnt >= l)
        {
            high = avg - 1;
            ans = avg;
        }
        else
            low = avg + 1;
    }
    cout << ans;
}