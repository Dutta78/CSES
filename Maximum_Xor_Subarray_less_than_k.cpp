#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode *left;
    trieNode *right;
};

class Trie
{
public:
    Trie *val[26];
};
void insert1(Trie *head, string s)
{
    Trie *curr = head;
    for (int i = 0; i < s.size(); i++)
    {
        int l = s[i] - 'a';

        if (!curr->val[l])
        {
            curr->val[l] = new Trie();
        }
        curr = curr->val[l];
    }
}

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
int main()
{
    string s;
    cin >> s;
    Trie *head = new Trie();
    insert1(head, s);
    cout << 1;
    return 0;
}