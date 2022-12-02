#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main()
{
    int n;

    cin >> n;
    long long res = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            res += gcd(j, i);
        }
    }

    cout << res;

    return 0;
}