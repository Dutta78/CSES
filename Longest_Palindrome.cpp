#include <bits/stdc++.h>
using namespace std;

void manachar(string &T)
{
    // int[] P = new int[T.size()];
    vector<int> P(T.size());
    int C = 0, R = 0;
    for (int i = 1; i < T.size() - 1; i++)
    {
        int mirr = 2 * C - i;
        if (i < R)
        {
            P[i] = min(R - i, P[mirr]);
        }
        while (T[i + (P[i] + 1)] == T[i - (P[i] + 1)])
        {
            P[i]++;
        }
        if (i + P[i] > R)
        {
            R = P[i] + i;
            C = i;
        }
    }
    int mx = -1;
    int mxpos = -1;
    for (int i = 0; i < T.size(); i++)
    {
        if (mx < P[i])
        {
            mx = P[i];
            mxpos = i;
        }
    }
    string s = "";
    for (int i = mxpos - P[mxpos]; i <= mxpos + P[mxpos]; i++)
        if (T[i] != '#')
            s += T[i];
    cout << s;
}
void solve(string &s)
{
    string p = "$#";
    for (char d : s)
    {
        p += d;
        p += "#";
    }
    p += "@";
    manachar(p);
}
int main()
{
    string s;
    cin >> s;
    solve(s);
}