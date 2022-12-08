#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, t;

    scanf("%d %d", &n, &t);

    int boxLine[n + 1];

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &boxLine[i]);
    }

    for (int i = 0; i < t; ++i)
    {
        int q, x, y;
        scanf("%d", &q);
        if (q == 1)
        {
            scanf("%d %d", &x, &y);
            if (boxLine[x] < y)
                boxLine[x]++;
        }
        else if (q == 2)
        {
            scanf("%d %d", &x, &y);
            if (boxLine[x] >= y)
                boxLine[x]--;
        }
        else if (q == 3)
        {
            scanf("%d %d", &x, &y);
            for (int j = x - 1; j <= x + 1; j++)
            {
                if (j > 0 && j <= n)
                {
                    if (boxLine[j] >= y + 1)
                    {
                        boxLine[j]--;
                    }
                    if (boxLine[j] >= y)
                    {
                        boxLine[j]--;
                    }
                    if (y - 1 > 0 && boxLine[j] >= y - 1)
                    {
                        boxLine[j]--;
                    }
                }
            }
        }
        else
        {
            scanf("%d", &y);
            for (int j = 1; j <= n; j++)
            {
                if (boxLine[j] >= y)
                    boxLine[j]--;
            }
        }

        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", boxLine[j]);
        }
        printf("\n");
    }

    return 0;
}