#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long x;
    cin >> x;
    // printf("%lld", x);
    //  double s = ;
    long ans = floor(sqrt(x));
    if (sqrt(x) == floor(sqrt(x)))
        ans--;

    cout << ans;

    return 0;
}