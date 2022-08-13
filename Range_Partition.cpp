#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp;
bool find1(int n, int sum, int op, vector<int> &ar, int pos = 1, int cal = 0)
{
    /*if (cal == sum)
    {
        // if(!cs(ar,op,n))return false;
        return true;
    }
    if (cal > sum)
        return false;
    if (pos > n)
        return false;
    ar.push_back(pos);
    if (find1(n, sum, op, ar, pos + 1, cal + pos))
        return true;
    ar.pop_back();
    return find1(n, sum, op, ar, pos + 1, cal);*/
    int i = 1;
    int j = n;
    int real = 0;
    while (j > 0 && real != sum)
    {
        if (real + j <= sum)
        {
            real += j;
            ar.push_back(j);
        }
        j--;
    }
    return real == sum;
}
int main()
{
    int tc;
    cin >> tc;
    for (int tr = 1; tr <= tc; tr++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        /*int lc = lcm(x, y);
        x = x / lc;
        y = y / lc;*/
        // ax+ay = n;
        // find a;
        int a = (n * (n + 1));
        int mod = (2 * x + 2 * y);
        // a = a / 2;
        bool flag = false;
        cout << "Case #" << tr << ": ";
        vector<int> ar;

        if (a % mod != 0)
            flag = true;

        a = a / mod;
        int sum = a * x;

        // dp = vector<vector<int>>(sum,vector<int>());

        if (flag == false && sum > 0 && find1(n, sum, a * y, ar))
        {
            cout << "POSSIBLE"
                 << "\n";
            cout << ar.size() << "\n";
            for (int i = ar.size() - 1; i >= 0; i--)
            {
                cout << ar[i] << " ";
            }
            // cout << i << " ";
        }
        else
            cout << "IMPOSSIBLE";
        cout << "\n";
    }
}