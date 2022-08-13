#include <bits/stdc++.h>
using namespace std;
void buildTree(vector<long long> &ar, long long *tree, long long start, long long end, long long treeNode)
{
    if (start >= end)
    {
        tree[treeNode] = ar[start];
        return;
    }
    long long mid = (start + end) / 2;

    buildTree(ar, tree, start, mid, 2 * treeNode);
    buildTree(ar, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = max(tree[2 * treeNode], tree[2 * treeNode + 1]);
    // cout << start << " " << end << " " << tree[treeNode] << "\n";
}
long long query(long long *tree, long long start, long long end, long long left, long long right, long long treeNode = 1)
{
    if (right < start || left > end)
        return -1e18;

    if (left <= start && right >= end)
    {
        // return ar[]
        // cout << tree[treeNode] << " ";
        return tree[treeNode];
    }

    long long mid = (start + end) / 2;
    return max(query(tree, start, mid, left, right, 2 * treeNode), query(tree, mid + 1, end, left, right, 2 * treeNode + 1));
}
int main()
{
    // freopen("/home/arjun/Downloads/test_input(7).txt", "r", stdin);
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> ar(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (long long i = 1; i < n; i++)
        ar[i] += ar[i - 1];
    // long long ans = -1e18;
    long long ans = ar[a - 1];
    ans = max(ans, ar[b - 1]);

    // vector<long long>next

    long long *tree = new long long[6000000];

    buildTree(ar, tree, 0, n - 1, 1);

    for (long long i = 0; i < n; i++)
    {
        if (i + a >= n)
            break;
        long long k = min(i + b, n - 1);
        long long mx = query(tree, 0, n - 1, i + a, k, 1);
        /*

        for (long long j = i + a; j <= i + b && j < n; j++)
        {
            ans = max(ans, ar[j] - ar[i]);
        }

        */
        ans = max(ans, mx - ar[i]);

        // cout << ar[i] << " " << mx << endl;
    }
    ans = max(ans, query(tree, 0, n - 1, a - 1, b - 1, 1));
    //*/
    cout << ans;
}