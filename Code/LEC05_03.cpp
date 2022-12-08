#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    stack<string> st;
    string x = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '[')
        {
            st.push(x);
            x = "";
        }
        else if (s[i] == ']')
        {
            while (!st.empty())
            {
                string t = st.top();
                x += t;
                st.pop();
            }
        }
        else
        {
            x += s[i];
        }
    }
    while (!st.empty())
    {
        string t = st.top();
        x += t;
        st.pop();
    }

    cout << x;
}