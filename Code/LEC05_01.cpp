#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    scanf("%d", &n);

    int arr[n], sum = 0;

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] - (sum / n) > 0)
        {
            result += arr[i] - (sum / n);
        }
    }

    printf("%d", result);

    return 0;
}