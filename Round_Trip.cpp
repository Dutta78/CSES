#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = -1;
int lk = 0;
vector<int> vis;
vector<int> ret;
bool dfs(vector<vector<int>> &ar, int u, int par = 0)
{
    if (vis[u] != -1)
    {
        ret.push_back(u);
        // cout << u << " ";
        //  lk=1;
        ans = u;
        return true;
    }
    vis[u] = 1;
    for (int child : ar[u])
    {
        if (child == par)
            continue;
        if (dfs(ar, child, u))
        {
            if (lk == 1)
                return true;
            ret.push_back(u);
            // cout << u << " ";
            if (u == ans)
            {
                lk = 1;
            }
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    vector<vector<int>> ar(n + 1);
    int e1, e2;

    for (int i = 0; i < m; i++)
    {
        cin >> e1 >> e2;
        ar[e1].push_back(e2);
        ar[e2].push_back(e1);
    }
    vis = vector<int>(n + 1, -1);
    bool flag = dfs(ar, e1);

    if (!flag)
    {
        vis = vector<int>(n + 1, -1);
        bool flat = dfs(ar, 1);

        if (!flat)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << ret.size() << endl;
    for (int i : ret)
        cout << i << " ";
    return 0;
}