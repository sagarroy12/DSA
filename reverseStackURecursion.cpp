#include <bits/stdc++.h>
using namespace std;

void reversing(stack<int> s, stack<int> &r)
{
    if (s.empty())
    {
        return;
    }
    r.push(s.top());
    s.pop();
    reversing(s, r);
}

stack<int> reverseF(stack<int> s)
{
    if (s.empty())
    {
        return s;
    }
    stack<int> r;
    reversing(s, r);
    return r;
}

void printS(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{

    stack<int> s;
    s.push(12);
    s.push(34);
    s.push(3);
    s.push(2);
    s.push(53);

    printS(s);

    s = reverseF(s);

    printS(s);

    return 0;
}