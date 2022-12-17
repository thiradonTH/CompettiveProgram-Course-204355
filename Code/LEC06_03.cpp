#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string s)
{
    vector<string> res;
    string r = "";

    for (int i = 0; i < s.length(); ++i)
    {
        if (isalpha(s[i]))
        {
            r += tolower(s[i]);
        }
        else
        {
            res.push_back(r);
            r = "";
        }
    }
    res.push_back(r);
    return res;
}

int main()
{
    string s;
    set<string> ans;
    while (cin >> s)
    {
        vector<string> split = split_string(s);

        for (auto i : split)
        {
            ans.insert(i);
        }
    }

    for (auto w : ans)
    {
        if (w.length() > 0)
        {
            cout << w << "\n";
        }
    }
    return 0;
}