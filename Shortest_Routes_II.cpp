#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    // n = cities
    // m = roads
    // q = queries
    vector<vector<long long int>> ar(n + 1, vector<long long int>(n + 1, 1e16));
    for (int i = 0; i <= n; i++)
        ar[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        ar[a][b] = min(ar[a][b], c);
        ar[b][a] = ar[a][b];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
                ar[j][i] = ar[i][j];
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (ar[a][b] == 1e16)
        {
            cout << -1 << endl;
        }
        else
            cout << ar[a][b] << endl;
    }
}