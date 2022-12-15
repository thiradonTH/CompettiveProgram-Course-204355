#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> buffet_time;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        buffet_time.push_back(make_pair(b, a));
    }
    sort(buffet_time.begin(), buffet_time.end());
    int cnt = 1, last_res = buffet_time[0].first;
    for (int i = 1; i < n; ++i)
    {
        if (buffet_time[i].second >= last_res)
        {
            cnt++;
            last_res = buffet_time[i].first;
        }
    }

    printf("%d", cnt);

    return 0;
}