#include <bits/stdc++.h>
using namespace std;

// void reversing(stack<int> s, stack<int> &r)
// {
//     if (s.empty())
//     {
//         return;
//     }
//     r.push(s.top());
//     s.pop();
//     reversing(s, r);
// }

void insertAtBottom(stack<int>&s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int save = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(save);


}

void reverseF(stack<int> &s)
{
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverseF(s);
    insertAtBottom(s,x);
    
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

    reverseF(s);

    printS(s);

    return 0;
}