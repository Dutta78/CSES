#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n m
    //
    // freopen ("/home/arjun/Downloads/test_input(1).txt","r",stdin);
    // freopen("",STDIN);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ar(n + 1);
    for (int i = 0; i < m; i++)
    {
        int e1, e2, cost;
        cin >> e1 >> e2 >> cost;
        ar[e1].push_back({e2, cost});
    }
    vector<long long int> dist(n + 1, 1e17);
    dist[1] = 0;
    priority_queue<pair<long long int, int>> pq;
    pq.push({0, 1});
    vector<bool> vis(n + 1, 0);

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        long long cost = temp.first;
        int pos = temp.second;

        if (vis[pos])
            continue;

        vis[pos] = true;

        for (auto v : ar[pos])
        {
            int child = v.first;
            int cost1 = v.second;
            long long real_cost = -1 * cost1;
            real_cost += cost;
            if (dist[child] > dist[pos] + cost1)
            {
                dist[child] = dist[pos] + cost1;
                pq.push({real_cost, child});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}