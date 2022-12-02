#include <bits/stdc++.h>

using namespace std;
int gcd(int x, int y)
{
    if (x < y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    if (y == 0)
        return x;

    return gcd(y, x % y);
}
int main()
{
    int n;
    vector<int> arr;
    while (cin >> n)
    {
        arr.push_back(n);
    }
    int mx = 1;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            mx = max(mx, gcd(arr[i], arr[j]));
        }
    }

    cout << mx;
}