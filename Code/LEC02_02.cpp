#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;

    cin >> n;

    long long res = 0LL;

    for (int i = 1; i <= n; ++i)
    {
        res += i * (n - i + 1);
    }

    cout << res;

    return 0;
}
