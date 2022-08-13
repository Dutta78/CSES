#include <bits/stdc++.h>
using namespace std;
struct triple
{
    int ind[3];
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> time(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> time[i][0] >> time[i][1];
        time[i][2] = i;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++)
    {
        vector<int> v(3);
        v[0] = time[i][0];
        v[1] = 0;
        v[2] = i;
        pq.push(v);
        vector<int> end(3);
        end[0] = time[i][1];
        end[1] = 1;
        end[2] = i;
        pq.push(end);
    }
    int rooms_occ = 0;
    vector<int> ret(n);
    queue<int> q;
    int ans = 0;
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int l = v[2];
        if (v[1] == 1)
        {
            q.push(ret[l]);
        }
        else
        {
            if (q.empty())
            {
                rooms_occ++;
                q.push(rooms_occ);
            }
            int empty_room = q.front();
            q.pop();
            ret[l] = empty_room;
        }
    }
    cout << rooms_occ << endl;
    for (int i : ret)
        cout << i << " ";
}