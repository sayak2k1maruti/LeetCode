#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int N1 = nums1.size();
        int N2 = nums2.size();
        int N = N1 + N2;
        int n1, n2;
        if (N % 2 == 0)
        {
            n1 = N / 2;
            n2 = n1 + 1;
        }
        else
        {
            n1 = (N + 1) / 2;
            n2 = n1;
        }
        int i = 0, j = 0;
        int count = 0;
        double ans1 = 0;
        while (i < N1 && j < N2)
        {
            int temp;
            if (nums1[i] < nums2[j])
            {
                count++;
                temp = nums1[i++];
            }
            else
            {
                count++;
                temp = nums2[j++];
            }
            if (count == n1)
                ans1 = temp;
            else if (count == n2)
                return (ans1 + temp) / 2;
        }
        while (i < N1)
        {
            count++;
            if (count == n1)
                ans1 = nums1[i];
            else if (count == n2)
                return (ans1 + nums1[i]) / 2;
            i++;
        }
        while (j < N2)
        {
            count++;
            if (count == n1)
                ans1 = (double)nums2[j];
            else if (count == n2)
                return (ans1 + nums2[j]) / 2;
            j++;
        }
        return ans1;
    }
};