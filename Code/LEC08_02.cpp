#include <bits/stdc++.h>

using namespace std;

void buildTree(int node, int a, int b, int *tree, int *input, int *nodeCount)
{
    if (a > b)
    {
        return;
    }

    if (a == b)
    {
        tree[node] = input[a];
        nodeCount[node] = 1;
        return;
    }

    buildTree(node * 2, a, (a + b) / 2, tree, input, nodeCount);
    buildTree(node * 2 + 1, 1 + (a + b) / 2, b, tree, input, nodeCount);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    nodeCount[node] = nodeCount[node * 2] + nodeCount[node * 2 + 1];

    return;
}

void updateTree(int node, int a, int b, int i, int j, int *tree, int value)
{
    if (a > b || a > j || i > b)
    {
        return;
    }

    if (a == b)
    {
        tree[node] = value;
        return;
    }

    updateTree(node * 2, a, (a + b) / 2, i, j, tree, value);
    updateTree(node * 2 + 1, 1 + (a + b) / 2, b, i, j, tree, value);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);

    return;
}

int queryTree(int node, int a, int b, int i, int j, int *tree, int *nodeCount, int k)
{
    if (a > b || a > j || i > b)
    {
        return 0;
    }

    if (a >= i && b <= j && tree[node] <= k)
    {
        return nodeCount[node];
    }

    int resLeft = queryTree(node * 2, a, (a + b) / 2, i, j, tree, nodeCount, k);
    int resRight = queryTree(node * 2 + 1, 1 + (a + b) / 2, b, i, j, tree, nodeCount, k);

    return resLeft + resRight;
}

int main()
{
    int n, q;

    cin >> n >> q;

    int arr[n], tree[1000000], nodeCount[1000000];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    buildTree(1, 0, n - 1, tree, arr, nodeCount);
    // for (int i = 0; i < 2 * n; ++i)
    // {
    //     cout << tree[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < q; ++i)
    {
        char c;
        int x, y;

        scanf(" %c %d %d", &c, &x, &y);

        if (c == 'C')
        {
            int value;

            scanf("%d", &value);

            cout << queryTree(1, 0, n - 1, x - 1, y - 1, tree, nodeCount, value) << "\n";
        }
        else
        {
            updateTree(1, 0, n - 1, x - 1, x - 1, tree, y);
        }
    }

    return 0;
}