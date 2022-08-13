#include <bits/stdc++.h>
using namespace std;
// ans will be in long long
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar.begin(), ar.end());
    //  2 3 8
    //  1 2 3 4 5 6 7 8 9 10 11 12 1
    // K
    // J
    long long int sum = 0;
    long long int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += ar[i];
    }
    int i = n - 1;
    if (sum > ar[i])
    {
        cout << ar[i] + sum << "\n";
    }
    else
        cout << 2 * ar[i] << "\n";
}