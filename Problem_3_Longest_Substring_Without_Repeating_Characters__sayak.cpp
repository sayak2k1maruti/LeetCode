#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int i = 0, j = 1;
        int ans = 1;
        while (i < s.length() && j < s.length())
        {
            if (i == j)
            {
                j++;
            }
            else
            {
                bool flag = true;
                for (int z = i; z < j; z++)
                {
                    if (s[z] == s[j])
                    {
                        i++;
                        flag = false;
                    }
                }
                if (flag)
                {
                    ans = max(ans, j - i + 1);
                    j++;
                }
            }
        }
        return ans;
    }
};