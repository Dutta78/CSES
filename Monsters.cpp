#include <bits/stdc++.h>
using namespace std;
int n, m;
string ret = "";
void dfs(vector<vector<int>> &vis, int i, int j, vector<char> &c, int loop = 0)
{
    if (ret.size() != 0)
        return;

    if (i >= n || j >= m || i < 0 || j < 0)
    {
        for (int l = 0; l < c.size() - 1; l++)
            ret += c[l];
        return;
    }

    if (vis[i][j] <= loop)
        return;
    int temp = vis[i][j];
    vis[i][j] = loop + 1;
    c.push_back('L');
    dfs(vis, i, j - 1, c, loop + 1);
    c.pop_back();

    c.push_back('U');
    dfs(vis, i - 1, j, c, loop + 1);
    c.pop_back();

    c.push_back('D');
    dfs(vis, i + 1, j, c, loop + 1);
    c.pop_back();

    c.push_back('R');
    dfs(vis, i, j + 1, c, loop + 1);
    c.pop_back();
}
int main()
{
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<vector<char>> ar(n, vector<char>(m));
    pair<int, int> start;
    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'M')
            {
                vis[i][j] = 0;
                q.push({i, j});
            }
            if (ar[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            if (ar[i][j] == '#')
            {
                vis[i][j] = 0;
            }
        }
    }
    if (start.first == 0 || start.second == 0 || start.first == n - 1 || start.second == m - 1)
    {
        cout << "YES"
             << "\n";
        cout << 0;
        return 0;
    }
    int loop = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        // cout << cnt++ << " ";
        while (sz--)
        {
            auto temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second;

            if (i > 0 && vis[i - 1][j] > loop + 1)
            {
                vis[i - 1][j] = loop + 1;
                q.push({i - 1, j});
            }
            if (j > 0 && vis[i][j - 1] > loop + 1)
            {
                vis[i][j - 1] = loop + 1;
                q.push({i, j - 1});
            }
            if (i < (n - 1) && vis[i + 1][j] > loop + 1)
            {
                vis[i + 1][j] = loop + 1;
                q.push({i + 1, j});
            }
            if (j < (m - 1) && vis[i][j + 1] > loop + 1)
            {
                vis[i][j + 1] = loop + 1;
                q.push({i, j + 1});
            }
        }
        loop++;
    }
    vector<char> c;
    ret = "";

    dfs(vis, start.first, start.second, c);
    if (ret.size() == 0)
        cout << "NO";
    else
        cout << "YES"
             << "\n"
             << ret.size() << "\n"
             << ret;
    return 0;
}