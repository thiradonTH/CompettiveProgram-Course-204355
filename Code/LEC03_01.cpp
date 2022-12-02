#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    long long arr[n + 10];

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
    }
    long long x = 0;
    long long mx = 0;
    for (int i = 0; i < n; ++i)
    {
        x += arr[i];
        if (x > mx)
            mx = x;

        if (x < 0)
            x = 0;
    }
    cout << mx;

    return 0;
}
