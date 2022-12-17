#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;
    bool next = false;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (next)
            break;
        for (int j = s[i] + 1; j <= 'z'; j++)
        {
            if (next)
                break;
            for (int k = i + 1; k < s.length(); k++)
            {
                if (j == int(s[k]))
                {
                    char temp = s[i];
                    s[i] = s[k];
                    s[k] = temp;
                    sort(s.begin() + i + 1, s.end());
                    next = true;
                    break;
                }
            }
        }
    }

    if (next)
        cout << s;
    else
        cout << "No Successor";
}