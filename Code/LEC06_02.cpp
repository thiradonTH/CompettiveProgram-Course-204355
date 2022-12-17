#include <bits/stdc++.h>

using namespace std;

int win_bye_count(vector<int> p)
{
    if (p.size() < 2)
    {
        return 0;
    }
    int count = 0;
    vector<int> next;
    for (int i = 0; i < p.size(); i += 2)
    {
        if (p[i] == p[i + 1])
        {
            next.push_back(p[i]);
        }
        else
        {
            next.push_back(1);
            count++;
        }
    }

    return count + win_bye_count(next);
}

int main()
{

    int r, m;
    scanf("%d %d", &r, &m);

    int n = pow(2, r);

    vector<int> player(n);
    fill(player.begin(), player.end(), 1);
    for (int i = 0; i < m; ++i)
    {
        int x;
        scanf("%d", &x);
        player[x - 1] = 0;
    }

    printf("%d", win_bye_count(player));
    return 0;
}