#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;

    getline(cin, s);

    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            for (int j = i - 1; j >= start; j--)
            {
                printf("%c", s[j]);
            }
            printf(" ");
            start = i + 1;
        }
    }
    for (int i = s.length() - 1; i >= start; i--)
    {
        printf("%c", s[i]);
    }

    return 0;
}