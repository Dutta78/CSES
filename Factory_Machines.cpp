#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen()
    // freopen("/home/arjun/Downloads.test_input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    vector<long long int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar.begin(), ar.end());
    long long int low = 0;
    long long int high = ar[0] * k;
    long long int ans = high;
    while (low <= high)
    {
        long long int avg = (low + high) / 2;
        long long int cnt = 0;
        for (int i : ar)
        {
            if (i == 0)
                continue;
            // long long int p = (long long)(i);
            cnt += (avg / i);
            // if (cnt >= k)
            // break;
        }
        if (cnt < k)
            low = avg + 1;
        else
        {
            high = avg - 1;
            ans = avg;
        }
    }
    cout << ans << "\n";
    return 0;
}