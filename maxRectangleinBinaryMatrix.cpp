#include <bits/stdc++.h>
using namespace std;



class Solution
{
private:

    void printL(vector<int> v){
        for(int i =0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<int>> &matrix)
    {
        if(matrix.size()==0){
            return -1;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int area = INT_MIN;
        for (int i = 0; i < row; i++)
        {
            vector<int> v(col);
            for (int j = 0; j < col; j++)
            {
                int count = 0;
                if (matrix[i][j] != 0)
                {
                    int k = i;
                    while (k >= 0 && matrix[k][j] != 0)
                    {
                        count++;
                        k--;
                    }
                }
                v[j] =count;
            }
            int newArea = largestRectangleArea(v);
            area = max(area, newArea);
        }
        return area;
    }
};

int main()
{

    vector<vector<int>> matrix = {{1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {1, 1, 1, 1, 1},
                                  {1, 0, 1, 1, 1}};
    Solution s;

    int ans = s.maximalRectangle(matrix);
    cout << ans;

    return 0;
}
