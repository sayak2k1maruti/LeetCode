#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int n = 0;
        // int x = abs(xx);
        while (x)
        {
            // cout<< x << " " << n << endl;
            if (n > 0 && n > (INT_MAX / 10 - x % 10 + 1))
                return 0;
            if (n < 0 && n < (INT_MIN / 10 + x % 10 + 1))
                return 0;
            n = n * 10 + x % 10;
            x = x / 10;
        }
        return n;
    }
};
int main()
{
    Solution sol;
    int x;
    cin >> x;
    cout << sol.reverse(x) << endl;
    return 0;
}