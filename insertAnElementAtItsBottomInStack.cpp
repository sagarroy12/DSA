#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int save = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(save);
    
}

int main()
{

    stack<int>s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    int btm = 33;

    insertAtBottom(s,btm);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}