#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ar(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i][0] >> ar[i][1];
    }
    sort(ar.begin(), ar.end());
    long long int time = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        time += ar[i][0];
        sum += (ar[i][1] - time);
    }
    cout << sum;
    return 0;
}