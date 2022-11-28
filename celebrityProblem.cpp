#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (M[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int x = s.top();

        for (int i = 0; i < n; i++)
        {
            if (M[x][i] != 0)
            {
                return -1;
            }
            if (M[i][x] != 1)
            {
                if (i == x)
                {
                    continue;
                }
                return -1;
            }
        }
        return x;
    }
};

int main()
{
    vector<vector<int>> M = { {0, 1, 1},{0,0,0},{1,1,1}};
    int n = 3;//no of people in the party;
    Solution s;
    

    int ans = s.celebrity(M,n);
    cout<<ans;
    
}
