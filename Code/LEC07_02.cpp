#include <bits/stdc++.h>

using namespace std;

int query(int l, int r, int height[], int block[], int block_size)
{
    int m = 0;

    while (l <= r)
    {
        if (l % block_size == 0 and l + block_size - 1 <= r)
        {
            if (m < block[l / block_size])
                m = block[l / block_size];
            l += block_size;
        }
        else
        {
            if (m < height[l])
                m = height[l];
            l++;
        }
    }

    return m;
}

int main()
{

    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n], sum[n], height[n], block[n], mx_block;

    int block_idex = -1, block_size = sqrt(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &height[i]);

        if (i % block_size == 0)
        {
            mx_block = height[i];
            block_idex++;
            block[block_idex] = height[i];
        }
        if (mx_block < height[i])
        {
            block[block_idex] = height[i];
            mx_block = height[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);

        if (i == 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%ld", query(x, y, height, block, block_size));

        if (x == 0)
        {
            printf(" %ld\n", sum[y]);
        }
        else
        {
            printf(" %ld\n", sum[y] - sum[x - 1]);
        }
    }
    return 0;
}