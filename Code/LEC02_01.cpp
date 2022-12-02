#include <bits/stdc++.h>

using namespace std;

void klopp(long long n, long long m, long long i)
{
    if (n == 1)
    {
        cout << m << " " << i;
        return;
    }
    if (n > m)
    {
        m = n;
    }

    if (n % 2 == 0)
    {
        klopp(floor(sqrt(n)), m, i + 1);
    }
    else
    {
        klopp(floor(sqrt(pow(n, 3))), m, i + 1);
    }

    return;
}

int main()
{
    long long n;

    cin >> n;

    klopp(n, n, 1);
    return 0;
}
