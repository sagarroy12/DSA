#include <bits/stdc++.h>
using namespace std;

void prevSmallElement(int arr[], int size, stack<int> &ans){
    if(size==0){
        return;
    }

    stack<int> s;
    s.push(-1);

    for(int i=0;i<size;i++){
        while(arr[i]<s.top()){
            s.pop();
        }
        int x = s.top();
        ans.push(x);
        s.push(arr[i]);

    }
}

void printF(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{

    int arr[] = {23, 12, 4, 20, 22, 10};
    stack<int> s;
    int size = sizeof(arr) / sizeof(arr[0]);
    prevSmallElement(arr, size, s);

    printF(s);

    return 0;
}