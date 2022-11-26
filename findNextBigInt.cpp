#include <bits/stdc++.h>
using namespace std;

void printF(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void findNextBigInt(int arr[], int size, stack<int> &ans)
{

    if (size == 0)
    {
        return;
    }

    stack<int> s;

    s.push(-1);

    for (int i = size - 1; i >= 0; i--)
    {

        while (arr[i] <= s.top())
        {
            s.pop();
        }

        int x = s.top();
        ans.push(x);
        s.push(arr[i]);
    }
}

int main()
{

    int arr[] = {5, 7, 9, 2, 6, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    stack<int> s;

    findNextBigInt(arr, size, s);

    // printF(s);

    return 0;
}