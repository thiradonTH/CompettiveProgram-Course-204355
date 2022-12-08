#include <bits/stdc++.h>

using namespace std;

int main()
{

    int alphabet[26];
    memset(alphabet, 0, sizeof(alphabet));

    string s;
    cin >> s;

    int res = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        char a = s[i];
        int j = int(a) - 65;
        while (alphabet[j] <= 0 && j <= 25)
        {
            j++;
        }
        if (j <= 25)
        {
            alphabet[j]--;
        }
        else
        {
            res++;
        }
        alphabet[int(a) - 65]++;
    }

    cout << res;
    return 0;
}