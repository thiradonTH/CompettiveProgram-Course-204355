#include <bits/stdc++.h>

using namespace std;

void buildCount(int node, int a, int b, int *counter, int *tree)
{
    int left = node * 2, right = node * 2 + 1, mid = (a + b) / 2;
    if (a > b)
        return;

    if (a == b)
    {
        tree[node] = 0;
        counter[node] = 1;
        return;
    }

    buildCount(left, a, mid, counter, tree);
    buildCount(right, 1 + mid, b, counter, tree);

    tree[node] = tree[left] + tree[right];
    counter[node] = counter[left] + counter[right];
}

void update(int node, int a, int b, int i, int j, int *tree, int *counter, int *lazy)
{
    int left = node * 2, right = node * 2 + 1, mid = (a + b) / 2;

    if (a >= i && b <= j)
        lazy[node]++;

    lazy[node] %= 2;

    if (lazy[node])
    {
        tree[node] = counter[node] - tree[node];
        if (a != b)
        {
            lazy[left] += 1;
            lazy[right] += 1;
        }
        lazy[node] = 0;
    }

    if (a > b || a > j || i > b || (a >= i && b <= j))
        return;

    update(left, a, mid, i, j, tree, counter, lazy);
    update(right, 1 + mid, b, i, j, tree, counter, lazy);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int a, int b, int i, int j, int *tree, int *counter, int *lazy)
{
    if (a > b || a > j || i > b)
        return 0;

    int left = node * 2, right = node * 2 + 1, mid = (a + b) / 2, q1, q2;
    lazy[node] %= 2;

    if (lazy[node])
    {
        tree[node] = counter[node] - tree[node];
        if (a != b)
        {
            lazy[left] += 1;
            lazy[right] += 1;
        }
        lazy[node] = 0;
    }

    if (a >= i && b <= j)
        return tree[node];

    q1 = query(left, a, mid, i, j, tree, counter, lazy);
    q2 = query(right, 1 + mid, b, i, j, tree, counter, lazy);

    return q1 + q2;
}

int main()
{

    int n, q;
    scanf("%d %d", &n, &q);

    int tree[500000], counter[500000], lazy[500000];
    fill(lazy, lazy + 500000, 0);
    buildCount(1, 0, n - 1, counter, tree);

    for (int i = 0; i < q; ++i)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        y--;
        z--;
        if (x == 0)
            update(1, 0, n - 1, y, z, tree, counter, lazy);
        else
            printf("%d\n", query(1, 0, n - 1, y, z, tree, counter, lazy));
    }

    return 0;
}