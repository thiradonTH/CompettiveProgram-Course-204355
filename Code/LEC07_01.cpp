#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, q;

    scanf("%d %d", &n, &q);

    int arr[n], sum[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x == 0)
        {
            printf("%d\n", sum[y]);
        }
        else
        {
            printf("%d\n", sum[y] - sum[x - 1]);
        }
    }
    return 0;
}