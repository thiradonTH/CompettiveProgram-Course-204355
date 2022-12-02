#include <bits/stdc++.h>

using namespace std;
bool prime[10010];

void seive_of_eratosthenes()
{
    prime[0] = true;
    prime[1] = true;

    for (int i = 2; i <= 10000; ++i)
    {
        if (prime[i])
            continue;

        for (int j = i + i; j <= 10000; j = j + i)
        {
            prime[j] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    seive_of_eratosthenes();

    int i = 0;

    while (i <= n)
    {
        if (!prime[i])
            cout << i << " ";

        i++;
    }

    return 0;
}