#include<limits.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int ans  = 0;
        while( x != 0) {
            
            int digit = x % 10;
            
            if( (ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }
            
            ans = (ans * 10) + digit;
            x = x / 10;
            
        }
        return ans;
    }
};

int main(){
    int x = 19373;
    Solution s;
    int rev = s.reverse(x);
    cout<<rev;
}