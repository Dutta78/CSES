#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode *left;
    trieNode *right;
};

void insert(int n, trieNode *head)
{
    trieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1;
        if (b == 0)
        {
            if (!curr->left)
            {
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(trieNode *head, int *arr, int n)
{

    int max_xor = INT_MIN;
    for (int j = 0; j < n; j++)
    {
        trieNode *curr = head;
        int sum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int b = (arr[j] >> i) & 1;

            if (b == 0)
            {
                if (curr->right)
                {
                    curr = curr->right;
                    sum += (1 << i);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr = curr->left;
                    sum += (1 << i);
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, sum);
    }
    return max_xor;
}

int max_xor_sub(trieNode *head, int *arr, int n)
{

    int max_xor = INT_MIN;
    for (int j = 0; j < n; j++)
    {
        max_xor = max(max_xor, arr[j]);

        trieNode *curr = head;
        int sum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int b = (arr[j] >> i) & 1;

            if (b == 0)
            {
                if (curr->right)
                {
                    curr = curr->right;
                    sum += (1 << i);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr = curr->left;
                    sum += (1 << i);
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, sum);
    }
    return max_xor;
}
int main()
{
    int n;
    cin >> n;
    trieNode *head = new trieNode();
    int arr[n];
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        a = a ^ arr[i];
        arr[i] = a;
        insert(a, head);
    }
    // cout << findMaxXorPair(head, arr, n);
    cout << max_xor_sub(head, arr, n);
}