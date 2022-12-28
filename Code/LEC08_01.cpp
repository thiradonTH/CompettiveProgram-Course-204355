#include <bits/stdc++.h>

using namespace std;

void add(int *tree, int k, int x, int n)
{
    while (k <= n)
    {
        tree[k] += x;
        k += (k & -k);
    }
}

int sumLiverpool(int *tree, int k)
{
    int res = 0;
    while (k >= 1)
    {
        res += tree[k];
        k -= (k & -k);
    }

    return res;
}

int main()
{
    int n, m, q;
    string t, s;

    scanf("%d", &n);

    // create string
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &m);
        cin >> t;
        for (int j = 0; j < m; ++j)
        {
            s += t;
        }
    }

    // pre process
    const int N = s.length() + 1;
    int tree[N], fan[N];
    fill(tree, tree + N, 0);
    for (int i = 0; i < N - 1; ++i)
    {
        if (s[i] == '0')
        {
            add(tree, i + 1, 0, N);
            fan[i + 1] = 0;
        }

        else
        {
            add(tree, i + 1, 1, N);
            fan[i + 1] = 1;
        }
    }

    // queries
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        a += 1;
        b += 1;

        if (c == 'F')
        {
            for (int j = a; j <= b; ++j)
            {
                if (fan[j] == 0)
                {
                    add(tree, j, 1, N);
                    fan[j] = 1;
                }
            }
        }
        else if (c == 'E')
        {
            for (int j = a; j <= b; ++j)
            {
                if (fan[j] == 1)
                {
                    add(tree, j, -1, N);
                    fan[j] = 0;
                }
            }
        }
        else if (c == 'I')
        {
            for (int j = a; j <= b; ++j)
            {
                if (fan[j] == 0)
                {
                    add(tree, j, 1, N);
                    fan[j] = 1;
                }
                else
                {
                    add(tree, j, -1, N);
                    fan[j] = 0;
                }
            }
        }
        else
        {
            if (a - 1 == 0)
            {
                cout << sumLiverpool(tree, b) << "\n";
            }
            else
            {
                cout << sumLiverpool(tree, b) - sumLiverpool(tree, a - 1) << "\n";
            }
        }
    }

    return 0;
}