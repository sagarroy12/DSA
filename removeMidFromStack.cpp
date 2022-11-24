#include <bits/stdc++.h>
using namespace std;

void deleting(stack<int> &s, int mid, int count)
{

    if (count == mid)
    {
        s.pop();
        return;
    }

    int save = s.top();
    s.pop();
    count++;
    deleting(s, mid, count);
    s.push(save);
    return;
}

void deleteMid(stack<int> &s)
{
    int size = s.size();
    int mid = size / 2;
    int count = 0;
    deleting(s, mid, count);
    return;
}

int main()
{

    stack<int> s;
    int size;
    cout << "inter the size of the stack" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int x;
        cout << "inter an int to push in stack" << endl;
        cin >> x;
        s.push(x);
    }

    deleteMid(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}