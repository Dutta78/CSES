#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &vis, int pos)
{
    if (pos == 8)
        return 1;
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if (vis[pos][i] == 0)
        {
            int l = pos;
            int j = i;
            while (l < 8 && j < 8)
            {
                vis[l][j]++;
                l++;
                j++;
            }

            l = pos + 1;
            j = i - 1;
            while (l < 8 && j >= 0)
            {
                vis[l][j]++;
                l++;
                j--;
            }
            l = pos + 1;
            j = i;
            while (l < 8)
                vis[l++][j]++;

            ans += solve(vis, pos + 1);
            l = pos + 1;
            j = i;
            while (l < 8)
                vis[l++][j]--;

            l = pos;
            j = i;
            while (l < 8 && j < 8)
            {
                vis[l][j]--;
                l++;
                j++;
            }

            l = pos + 1;
            j = i - 1;
            while (l < 8 && j >= 0)
            {
                vis[l][j]--;
                l++;
                j--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<char>> ar(8, vector<char>(8));
    vector<vector<int>> vis(8, vector<int>(8, 0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == '*')
                vis[i][j] = 1;
        }
    }
    int ans = solve(vis, 0);
    cout << ans;
    return 0;
}