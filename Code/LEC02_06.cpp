#include <bits/stdc++.h>

using namespace std;

const long long h = 1e9 + 7;

int main()
{
    long long n;

    cin >> n;

    cout << ((n % h) * (n % h)) % h;

    return 0;
}