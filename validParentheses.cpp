#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string b)
{

    stack<char> s;
    for (int i = 0; i < b.length(); i++)
    {

        char ch = b[i];
        

        if (ch == '(' || ch== '{' || ch== '[')
        {
            s.push(ch);
        }
        else
        {

            if (!s.empty())
            {
                char top = s.top();
                if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}'))
                {
          
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main()
{

    string brackets = "{()]}";
    bool ans = isValidParenthesis(brackets);
    cout << ans << endl;

    return 0;
}
