#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<set<int>> courses;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        set<int> course = {};

        for (int j = 0; j < 5; ++j)
        {
            int code;
            scanf("%d", &code);
            course.insert(code);
        }
        courses.insert(course);
    }
    int mx = 0;
    for (auto i : courses)
    {
        int count = courses.count(i);
        if (count > mx)
            mx = count;
    }

    int ans = 0;
    for (auto i : courses)
    {
        int count = courses.count(i);
        if (count == mx)
            ans += 1;
    }

    printf("%d", ans);
    return 0;
}