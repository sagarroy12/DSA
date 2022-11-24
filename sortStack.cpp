#include <bits/stdc++.h>
using namespace std;

void sorting(stack<int> &s, int x)
{
    if(s.empty()){
        s.push(x);
        return;
    }
    else if(s.top()<=x){
        s.push(x);
        return;
    }

    int save = s.top();
    s.pop();
    sorting(s,x);
    s.push(save);
    
}

void sortS(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int save = s.top();
    s.pop();
    sortS(s);

    if (s.empty())
    {
        s.push(save);
    }
    else if (s.top() <= save)
    {
        s.push(save);
    }
    else
    {
        sorting(s, save);
    }
    
}

void printS(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{

    stack<int> s;

    s.push(2);
    s.push(6);
    s.push(24);
    s.push(22);
    s.push(5);

    sortS(s);

    printS(s);

    return 0;
}