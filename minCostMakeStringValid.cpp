#include <bits/stdc++.h>
using namespace std;

int mincostMakeStringvalid(string st)
{
    if (st.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < st.length(); i++)
    {

        char ch = st[i];
        if (ch == '}')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty() &&s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    int o = 0;//opening braces count;
    int c = 0;//closing braces count;
    while(!s.empty()){
        if(s.top()=='{')
        {
            o++;
        }
        else{
            c++;
        }
        s.pop();
    }
    int ans = (o+1)/2 + (c+1)/2;
    return ans;
}

int main()
{

    string s = "{{{}{{}}";
    int ans = mincostMakeStringvalid(s);
    cout << ans;

    return 0;
}