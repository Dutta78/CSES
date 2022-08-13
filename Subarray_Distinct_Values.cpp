#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    /* for (int i = 0; i < n; i++)
     {
         cin >> ar[i];
     }*/
    int cnt = 0;
    int j = 0;
    long long sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (mp[ar[i]] == 0)
            cnt++;
        mp[ar[i]]++;
        while (cnt > k)
        {
            mp[ar[j]]--;
            if (mp[ar[j]] == 0)
                cnt--;
            j++;
        }

        long long need = i - j + 1;
        sum += (need);
    }
    cout << sum;
}