#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length();
        if (n <= 2 || numRows == 1)
            return s;
        int cols = ceil(n / (numRows + numRows - 2) * 2) + 2;
        vector<vector<char>> v(numRows, vector<char>(cols, '!'));
        int index = 0;
        for (int j = 0; j < cols && index < n; j++)
        {

            if ((j + 1) % 2 == 0)
            {
                for (int i = numRows - 2; i >= 1 && index < n; i--)
                {
                    v[i][j] = s[index++];
                }
            }
            else
            {
                for (int i = 0; i < numRows && index < n; i++)
                {
                    v[i][j] = s[index++];
                }
            }
        }

        index = 0;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // cout << v[i][j] << " ";
                if (v[i][j] != '!')
                    s[index++] = v[i][j];
            }
            // cout << endl;
        }
        return s;
    }
};
int main()
{
    Solution S;
    int t;
    cin >> t;
    for (; t--;)
    {
        string s;
        int n;
        cin >> s >> n;
        cout << S.convert(s, n) << endl;
    }
    return 0;
}